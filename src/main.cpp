//
//  main.cpp
//  sortChrPos
//
//  Created by Gang Peng on 9/23/16.
//  Copyright © 2016 Gang Peng. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

#include "normal.h"

using namespace std;

class posInfo{
private:
    int chr;
    int pos;
    string info;
    bool withChr;
    
public:
    posInfo(int c, int p, string i, bool w);
    
    bool operator < (const posInfo & other) const;
    friend std::ostream & operator<< (std::ostream & os, const posInfo & pi);
};

posInfo::posInfo(int c, int p, string i, bool w){
    chr = c;
    pos = p;
    info = i;
    withChr = w;
}

bool posInfo::operator< (const posInfo & other) const {
    if(chr < other.chr){
        return true;
    } else if( chr == other.chr){
        if(pos < other.pos){
            return true;
        } else if(pos == other.pos){
            return(info.compare(other.info) < 0);
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::ostream & operator<<(std::ostream & os, const posInfo & pi) {
    if(pi.chr==23){
        if(pi.withChr){
            os <<"chrX";
        } else {
            os <<"X";
        }
    } else if(pi.chr == 24){
        if(pi.withChr){
            os <<"chrY";
        } else {
            os <<"Y";
        }
    } else if(pi.chr == 25){
        os <<"MT";
    } else {
        if(pi.withChr){
            os <<"chr" << pi.chr;
        } else {
            os << pi.chr;
        }
        
    }
    os <<'\t'<< pi.pos <<'\t' << pi.info <<endl;
    
    return os;
}


int main(int argc, const char * argv[]) {
    if(argc == 1){
        cout << "Sort the lines in file according to chromosome and position" << endl;
        cout << "Usage: " <<endl;
        cout << "sortChrPos inputfile outputfile"<<endl;
        cout << "both inputfile and outputfile should be set. " <<endl;
    }
    if(argc == 2){
        cerr << "Both input and output file should be set." <<endl;
        return -1;
    }
    
    ifstream fin(argv[1]);
    if(!fin.is_open()){
        cerr << "Cannot ope file "<<argv[1]<<endl;
        return -1;
    }
    ofstream fout(argv[2]);
    
    set<posInfo> allPos;
    
    
    while(!fin.eof()){
        string fline;
        getline(fin, fline);
        if(fline.size() < 2){
            break;
        }
        
        
        vector<string> vsline = split(fline, "\t");
        int chr, pos;
        string info;
        string chrTmp;
        bool withChr;
        string vs0 = vsline[0];
        std::transform(vs0.begin(), vs0.end(),vs0.begin(), ::toupper);
        if(vs0.substr(0, 3) == "CHR"){
            chrTmp = vsline[0].substr(3);
            withChr = true;
        } else {
            chrTmp = vsline[0];
            withChr = false;
        }
         
     
        
        if(chrTmp == "X" || chrTmp == "x"){
            chr = 23;
        } else if(chrTmp == "Y" || chrTmp == "y"){
            chr = 24;
        } else if(chrTmp == "MT" || chrTmp == "mt"){
            chr = 25;
        } else {
            chr = atoi(chrTmp.c_str());
        }
        
        
        pos = atoi(vsline[1].c_str());
        if(vsline.size() == 2){
            info = "";
        }
        else {
            info = vsline[2];
            for(size_t i = 3; i < vsline.size(); i++){
                info = info + "\t" + vsline[i];
            }
        }
        
        posInfo tmp(chr, pos, info, withChr);
        allPos.insert(tmp);
        
    }
    fin.close();
    fin.clear();
    
    for(set<posInfo>::iterator it = allPos.begin(); it != allPos.end(); it++){
        fout<<*it;
    }
    fout.close();
    fout.clear();
    
    
    return 0;
}
