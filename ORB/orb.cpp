
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>
#include "orb.hpp"

using namespace std;
using namespace cv;

namespace orb {
    bool compare_keypoint_response(KeyPoint A, KeyPoint B) {
        return A.response > B.response;
    }

    void Orb(  Mat input_image, string path_Key_Point, string path_Descriptors,
                vector<vector<int> > areas,
                int nFeatures /*= 500*/ , int scaleFactor /*= 1.2*/, int nlevels /*= 8*/,
                int n_keypoint_confident /*= 100*/) {


        Mat input_image_gray;
        cvtColor(input_image, input_image_gray, CV_BGR2GRAY);

        Ptr<ORB> detector = ORB::create(nFeatures, scaleFactor, nlevels);

        for(int i = 0, areas_size = areas.size(); i < areas_size; ++i) {
            vector<int> it = areas[i];
            int x = it[0], y = it[1], w = it[2], h = it[3];

            Mat sub_image = input_image(Rect(x, y, w, h)).clone();
            Mat sub_image_gray;
            cvtColor(sub_image, sub_image_gray, CV_BGR2GRAY);

            vector<KeyPoint> key_point;
            Mat descriptor;

            detector->detect(sub_image_gray, key_point);
            sort(key_point.begin(), key_point.end(), compare_keypoint_response);
            if (key_point.size() > n_keypoint_confident) key_point.resize(n_keypoint_confident);
            detector->compute(sub_image_gray, key_point, descriptor);

            //Saving KeyPoint and Descriptors
            try{
                FileStorage fk (path_Key_Point + to_string(i) + ".yml", FileStorage::WRITE);
                write(fk, "KeyPoints", key_point);
                fk.release();
            }
            catch (...){
                cout<< "Ban chua khoi tao folder chua KeyPoints" <<endl;
            }

            try {
                FileStorage fd (path_Descriptors + to_string(i) + ".yml", FileStorage::WRITE);
                write(fd, "Descriptors", descriptor);
                fd.release();
            }
            catch (...) {
                cout<< "Ban chua khoi tao folder chua Descriptor" <<endl;
            }

            //---------------------------------------------------
            Mat out1;
            drawKeypoints(sub_image, key_point, out1);
            imshow("Keypoint " + to_string(i), out1);
        }

        //Draw Local KeyPoint Detected

        for(int i = 0, areas_size = areas.size(); i < areas_size; ++i) {
            vector<int> it = areas[i];
            int x = it[0], y = it[1], w = it[2], h = it[3];
            int x1 = x, y1 = y, x2 = x + h, y2 = y + w;

            line(input_image, Point2f(x1, y1), Point2f(x1, y2), Scalar(0, 255, 0), 5);
            line(input_image, Point2f(x1, y2), Point2f(x2, y2), Scalar(0, 255, 0), 5);
            line(input_image, Point2f(x2, y2), Point2f(x2, y1), Scalar(0, 255, 0), 5);
            line(input_image, Point2f(x2, y1), Point2f(x1, y1), Scalar(0, 255, 0), 5);

        } 

        imshow("origin_image", input_image);
        waitKey(0);
        destroyAllWindows();
    }

} // ORB detector