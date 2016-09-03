//
//  main.cpp
//  CODEGROUND
//
//  Created by 이민석 on 2016. 9. 3..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    
    cin >> t;
    
    int c = t;
    
    while (t--) {
        
        int n;
        
        cin >> n;
        
        long long N;
        
        vector<long long> v;
        
        for (int i=0; i<n; i++) {
            cin >> N;
            v.push_back(N);
        }
        
        sort(v.begin(), v.end());
        
        vector<long long> _xor;
        int count=1;
        long long k = v.back();
        while(!v.empty()){
            v.pop_back();
            if(k == v.back()){
                count++;
            } else {
                if(count%2 == 1){
                    _xor.push_back(k);
                    count = 1;
                    k = v.back();
                }
                else {
                    k = v.back();
                    count = 1;
                }
            }
        }
        
        long long result = 0;
        for (int i=0; i<_xor.size(); i++) {
            result ^= _xor[i];
        }

        
        cout << "Case #" << c-t << endl << result << endl;
        
        v.clear();
        _xor.clear();
        result = 0;
    }
    
    return 0;
}
