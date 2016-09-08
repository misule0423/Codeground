//
//  main.cpp
//  easy_5
//
//  Created by 이민석 on 2016. 9. 6..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

char dir[300010];

int main(int argc, const char * argv[]) {

    int t;
    
    cin >> t;
    
    int c = t;
    
    while (t--) {
        int n, k;
        
        cin >> n >> k;
        
//    cin 다음에 바로 getline을 사용할 수 없다. 왜냐하면 ' '인 공백을 문자로 인지하기 때문이다.
//        cin.ignore();
//        char dir[k+1];
//        cin.getline(dir, k+1);
        
        cin >> dir;
        
        int x = 1;
        int y = 1;
        long long total = 1;
        long long result = 1;
        
        for (int i=0; i<k; i++) {
            if(dir[i] == 'U')
                y--;
            else if(dir[i] == 'D')
                y++;
            else if(dir[i] == 'L')
                x--;
            else if(dir[i] == 'R')
                x++;
            
//            x+y-1은 몇번째 대각선인지를 나타낸다
            int line = x+y-1;
            
            if( line <= n){
                if( (line)%2 == 1)
                    result = line * (line-1) / 2 + x;
                else
                    result = line * (line-1) / 2 + y;
            }
//            n의 대각선을 기준으로 대칭이 되는 line을 구하고 위의 식처럼 계차 수열인 전의 라인 값의 최소값을 구한다.
//            마찬가지로 위의 식처럼 전 라인의 최소값에 n-x 또는 x-y만큼 더해준다.
            else {
                int par = 2 * n - line;
                if( (line)%2 == 1)
                    result = n*n - (par * (par-1) / 2 + n-x);
                else
                    result = n*n - (par * (par-1) / 2 + n-y);
                
            }
            
            total += result;
        }
        
        cout << "Case #" << c-t << endl << total << endl;
    }
    
    
    
   
    return 0;
}
