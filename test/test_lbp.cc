#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "feature.h"
#include "util.h"

int main(int argc, const char* argv[]) {
  if (argc != 2) return -1;
  auto m = cv::imread(argv[1]);
  cv::imshow("image", m);
  cv::cvtColor(m, m, CV_BGR2GRAY);
  auto lbp = feature::lbp::get(m).mat();
  cv::imshow("lbp", lbp);
  cv::imshow("hist", util::draw_hist(feature::histogram::get(lbp), 300, 512));
  cv::waitKey(0);

  return 0;
}
