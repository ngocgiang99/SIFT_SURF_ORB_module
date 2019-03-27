#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include "SURF/surf.hpp"
#include "ORB/orb.hpp"
#include "SIFT/sift.hpp"

using namespace std;
using namespace cv;

int main() {

    Mat image = imread("images/book_origin.png", IMREAD_COLOR);

    vector<vector<int> > areas;
    vector<int> rect1, rect2;
    rect1.push_back(50);
    rect1.push_back(50);
    rect1.push_back(400);
    rect1.push_back(400);
    areas.push_back(rect1);
    rect2.push_back(300);
    rect2.push_back(100);
    rect2.push_back(400);
    rect2.push_back(400);
    areas.push_back(rect2);


    sift::Sift(   image, "KeyPoints/", "Descriptors/",
            areas,
            500, 4, 1.6, 0.03, 10,  
            100);
    //cout<< add(5, 6) <<endl;
    //cout<< add(5, 6, 2) <<endl;

    waitKey(0);
    return 0;
}   