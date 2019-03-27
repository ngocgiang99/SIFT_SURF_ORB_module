#ifndef _ORB_HPP
#define _ORB_HPP

#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

using namespace std;
using namespace cv;

namespace orb {
    bool compare_keypoint_response(KeyPoint A, KeyPoint B);

    void Orb(  Mat input_image, string path_Key_Point, string path_Descriptors,
            vector<vector<int> > areas,
            int nFeatures = 500, int scaleFactor = 1.2, int nlevels = 8,
            int n_keypoint_confident = 100) ;
}
#endif