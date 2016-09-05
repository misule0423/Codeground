//
//  main.cpp
//  easy_3
//
//  Created by 이민석 on 2016. 9. 5..
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
        
        int n, k;
        
        cin >> n >> k;
        
        int grade[n];
        
        for (int i=0; i<n; i++) {
            cin >> grade[i];
        }
        
        sort(grade, grade+n, greater<int>());
        
        int res = 0;
        
        for (int i=0; i<k; i++) {
            res += grade[i];
        }
        
        cout << "Case #" << c-t << endl << res << endl;
        
    }
    
    return 0;
}
