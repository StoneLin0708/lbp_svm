#include "dataset.h"
#include "util.h"
#include <opencv2/ml.hpp>

using cv::ml::SVM;

int main(int argc, const char* argv[]) {
  if (argc < 2) return -1;
  const std::string save_path{"model.xml"};
  auto svm = SVM::create();
  svm->setType(cv::ml::SVM::NU_SVC);
  svm->setKernel(SVM::RBF);
  svm->setNu(0.1);
  // svm->setC(0.019);
  // svm->setP(0);
  // svm->setGamma(0.4);
  // svm->setTermCriteria(
      // cv::TermCriteria(cv::TermCriteria::Type::EPS, 10000, 1e-7));
  dataset data;
  if (!data.load(argv[1], 48, 40)) return -2;
  auto d = data.get(0.1);
  svm->trainAuto(d.train);
  svm->save(save_path);
  std::cout<<util::error(util::test(svm, d.test),d.test->getResponses())<<'\n';
}
