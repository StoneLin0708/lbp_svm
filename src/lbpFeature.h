#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

class lbpFeature{
public:
    lbpFeature(void);
    ~lbpFeature(void);

    void operator=(const lbpFeature&);

    bool outputFile(const char* path);
    bool saveK(void);
    int  k(int number);
    int  h(unsigned char number){return histogram[number];};
    void clear();
//
    void drawLBP(const char* title);
//
    int height;
    int width;
    int histogram[256];
    int sortList[256];

    std::vector <unsigned char>LBP;

private:

    int _saveCounter;
    std::ofstream _outFile;

};

class lbpFeatureEvaluator{
public:

    lbpFeatureEvaluator(void);
    //~lbpFeatureEvaluator(void);
    void loadImage(cv::Mat image,bool toLBP = true);
    unsigned char countLBPat(int col,int row);
    void countLBP(void);
    //load lbpMap to feature
    bool loadMap(std::vector<unsigned char>& lbp, int rows, int cols);

    //count histogram and sort
    void countHistogram(void);
    //( six function below ) count histogram without sort
    void countHistogram(cv::Rect area);
    void countHistogramArea(void);
    //( four function below ) need count histogram at last once before
    //count histogram in new area(just shift area x,y) with out clear old data
    void histogramUp(int shift);
    void histogramDown(int shift);
    void histogramLeft(int shift);
    void histogramRight(int shift);

    void pcaCalculate(void);
    //Data
    lbpFeature feature;
    cv::Rect area;

private:

    cv::Mat _image;
    std::ofstream _outFile;

};

class lbpFeatureGraph{
public:
    lbpFeatureGraph(void);
    lbpFeatureGraph(lbpFeature& feature);

    bool load(lbpFeature& feature);

    void drawLBPMap(const char* title);
    void drawHistogram(const char* title_histogram);
    void drawMapValue(const char* title,unsigned char lbpValue);
    void drawMapK(const char* title,unsigned char K_max,unsigned char K_min);

private:
    lbpFeature _feature;
};