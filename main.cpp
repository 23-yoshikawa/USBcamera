#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
string win_src = "src";

int main()
{
    Mat img_src;
    VideoCapture capture(0);
    if (!capture.isOpened())
    {
        cout << "error" << endl;
        return -1;
    }

    namedWindow(win_src, WINDOW_AUTOSIZE);

    while (1)
    {
        capture >> img_src;

        imshow(win_src, img_src);
        if (waitKey(1) == 'q')
            break;
    }
    capture.release();
    return 0;
}