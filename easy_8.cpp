//
//  main.cpp
//  easy_8
//
//  Created by 이민석 on 2016. 9. 25..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {

    int res[64];
    int test[64] = {0};
    
    for (int i = 1138; i>=1; i--) {
        
        int c = 0, x=i;
        
        while(x!=1){
            if(x%2==0)
                x = x/2;
            else
                x = 3*x+1;
            c++;
        }
        
        if(c<=63){
            res[c] = i;
            test[c] ++;
        }
    }
//    아래는 검증하는 방법이다. 만약 res[64]배열에 값이 들어가지 않았을때 그 배열의 인덱스를 출력하는것이다.
//    검증을 통하여 1138일때 63까지 모든 수를 커버할 수 있다.
//    for (int i=0; i<63; i++) {
//        if(test[i] ==0)
//            cout << i << " ";
//    }
//    cout << endl;
    
    int tc;
    
    cin >> tc;
    
    for (int testCase = 1; testCase <= tc ; testCase++) {
        
        int K;
        
        cin >> K;
        
        
//        만약 unsgined long long으로 선언하지 않고 int 및 long long 으로 선언하면 값이 초과한다.
//        그리고 만약 아래애서 형변환하지 않고 바로 출력하면 9.22337e+18 으로 표현된다.
        cout << "Case #" << testCase << endl << res[K] << " " << (unsigned long long)pow(2, K) << endl;
    }
    
    return 0;
}
