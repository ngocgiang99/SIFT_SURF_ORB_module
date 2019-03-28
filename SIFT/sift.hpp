
#ifndef _SIFT_HPP
#define _SIFT_HPP

#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


namespace sift {
    bool compare_keypoint_response(KeyPoint A, KeyPoint B);

    void Sift(  Mat input_image, string path_Key_Point, string path_Descriptors,
            vector<vector<int> > areas,
            int nFeatures = 0, int nOctaveLayers = 3, double sigma = 1.6, double constrastThreshold = 0.04, double egdeThreshold = 10,   
            int n_keypoint_confident = 100);

}

#endif