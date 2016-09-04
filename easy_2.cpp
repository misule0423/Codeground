//
//  main.cpp
//  easy_2
//
//  Created by 이민석 on 2016. 9. 3..
//  Copyright © 2016년 Roop. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int score[300000] = {0};

int main(int argc, const char * argv[]) {

    int t;
    
    cin >> t;
    
    int c = t;
    
    while (t--) {
    
        int n;
        
        cin >> n;
        
        for (int i=0; i<n; i++) {
            cin >> score[i];
        }
        
        sort(score, score+n);

        int max = 0;
        
        for (int i=0; i<n; i++) {
            if(score[i] + n - i > max)
                max = score[i] + n - i;
        }
        
        int count = 0;
        
        for (int i=0; i<n; i++) {
            if(score[i] + n >= max)
                count++;
        }
        
        cout << "Case #" << c-t << endl << count << endl;
        
    }
    
    return 0;
}
