

#ifndef _SURF_HPP
#define _SURF_HPP
#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace cv;

namespace surf {
    bool compare_keypoint_response(KeyPoint A, KeyPoint B);

    void Surf(  Mat input_image, string path_Key_Point, string path_Descriptors,
            vector<vector<int> > areas,
            int minHessian = 100, int nOctave = 4, int nScale = 3, 
            int n_keypoint_confident = 100) ;

}

#endif