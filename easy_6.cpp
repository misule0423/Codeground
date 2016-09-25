//
//  main.cpp
//  easy_6
//
//  Created by 이민석 on 2016. 9. 25..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    
    cin >> T;
    
    int c = T;
    
    while(T--){
        
        int N;
        
        cin >> N;
        
        deque<int> dq;
        
        dq.push_back(0);
        
        int ai;
        for (int i=0; i<N; i++) {
            cin >> ai;
            
            dq.push_back(ai);
        }
        
        
        int K;
        
        cin >> K;
        
        int temp1 = dq.front();
        int size = dq.size()-1;
        
        deque<int> dq2;
        
//        dq1의 각각의 차이를 구해서 dq2에 저장한다. 왜냐하면 차이값을 누적하면서 K보다 작을경우 result를 +1하면 된다.
//        이는 차이의 누적을 카운트 하면서 실제로
        while(size--){
            
            dq.pop_front();
            
            int temp2 = dq.front();
            
            dq2.push_back(temp2-temp1);
            
            temp1 = temp2;
            
        }
        
        int result = 0;
        int cul = 0;
        
        for (int i = 0; i<dq2.size(); i++) {
            if(dq2[i] > K){
                result = -1;
                break;
            } else {
                cul += dq2[i];
                
                if(cul > K){
                    cul = dq2[i];
                    result++;
                }
            }
        }
        
//        실제로 마지막 부분은 카운트되지 않는다. 그래서 +1 해준다.
        if(result != -1)
            result++;
        
        cout << "Case #" << c-T << endl << result << endl;
        
    }
    
    
    
    return 0;
}
