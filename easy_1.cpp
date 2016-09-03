
//
//  main.cpp
//  CODEGROUND
//
//  Created by 이민석 on 2016. 9. 3..
//  Copyright © 2016년 Roop. All rights reserved.
//

// 아래는 XOR 성질을 이용하였다. 어떤 수 x가 있을때 (x ^ 0) = x, (x ^ x) = 0 이 되는 성질을 이용하였다.
// 즉, 홀수, 짝수에 상관 없이 홀수번을 입력받으면 자기 자신이 되고, 짝수번을 입력받으면 0이되므로 수를 셀 필요 조차 없다.
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int t;
    
    cin >> t;
    
    int c = t;
    
    while (t--) {
        
        int n;
        
        cin >> n;
        
        int result = 0;
        int input = 0;
        
        for (int i=0; i<n; i++) {
            cin >> input;
            result ^= input;
        }
        
        cout << "Case #" << c-t << endl << result << endl;
        
    }
    
    return 0;
}

//아래는 n개를 입력 받고, 정렬한 후, 하나씩 pop 하면서 그 value의 갯수를 세고, 홀수일경우 새로운 벡터에 추가하였다.
//그리고 그것을 XOR하였다.
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    
//    int t;
//    
//    cin >> t;
//    
//    int c = t;
//    
//    while (t--) {
//        
//        int n;
//        
//        cin >> n;
//        
//        long long N;
//        
//        vector<long long> v;
//        
//        for (int i=0; i<n; i++) {
//            cin >> N;
//            v.push_back(N);
//        }
//        
//        sort(v.begin(), v.end());
//        
//        vector<long long> _xor;
//        int count=1;
//        long long k = v.back();
//        while(!v.empty()){
//            v.pop_back();
//            if(k == v.back()){
//                count++;
//            } else {
//                if(count%2 == 1){
//                    _xor.push_back(k);
//                    count = 1;
//                    k = v.back();
//                }
//                else {
//                    k = v.back();
//                    count = 1;
//                }
//            }
//        }
//        
//        long long result = 0;
//        for (int i=0; i<_xor.size(); i++) {
//            result ^= _xor[i];
//        }
//        
//        
//        cout << "Case #" << c-t << endl << result << endl;
//        
//        v.clear();
//        _xor.clear();
//        result = 0;
//    }
//    
//    return 0;
//}
