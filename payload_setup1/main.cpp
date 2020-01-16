#include <iostream>
#include <string.h>
#include "libverimb/pattern_loader.h"
#include "libverimb/ac/ac_adaptor.h"

using namespace std;

PatternSet patterns;
ACAdaptor* engine;


string pattern_path = "/Users/gengwei/Desktop/veriMB/payload_setup1/payload_setup1/snort_test.txt";

void print_patterns(PatternSet& ptns)
{
    for(int i=0; i < ptns.size(); i++)
    {
        for(int j = 0; j < ptns[i].size(); j++)
        {
            cout<<(char)ptns[i][j];
        }
        cout<<endl;
    }
}


int main(int argc, const char * argv[]) {
    
    //setup阶段
    
    /*读入处理好后的pattern文件*/
    PatternLoader::load_pattern_file(pattern_path.data(), patterns);
    //print_patterns(patterns);
    
    /*保存规则集id、规则数目meta和secret*/
    /*生成secret*/
    
    /*建AC树，AC树的结构保存在engine.ac中*/
    engine = new ACAdaptor();
    engine->init(patterns);
    
    /*计算每个节点的HMAC和每条规则的HMAC*/
    
    
    return 0;
}
