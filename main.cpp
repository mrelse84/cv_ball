#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat bond = imread("d:/images/halcon_images/die/die_03.png", IMREAD_GRAYSCALE);
	namedWindow("image");
	imshow("image", bond);
	waitKey();

	Mat bond_bin;
	threshold(bond, bond_bin, 100, 255, THRESH_BINARY);
	imshow("image", bond_bin);
	waitKey();
	vector<vector<Point> > contours;
	findContours(bond_bin, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);// 1, 2);
	Rect rect = boundingRect(bond_bin);

	return 0;
}