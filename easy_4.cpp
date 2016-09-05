//
//  main.cpp
//  easy_4
//
//  Created by 이민석 on 2016. 9. 5..
//  Copyright © 2016년 Roop. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

static int score[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };

int main(int argc, const char * argv[]) {
    
    int t1, t2;
    
    cin >> t1;
    
    t2 = t1;
    
    while (t1--) {
        
        int a,b,c,d,e;
        
        cin >> a >> b >> c >> d >> e;
        
        int n;
        
        cin >> n;
        
//        아래 처럼 저장해놓고 나중에 정렬하기 시작하면 점수가 마이너스 된다.
        
//        아래 Codeground에서는 컴파일 에러가 나온다. 이는 '>>'를 '> >'로 바꾸어주면 해결된다.
//        vector<pair<int, int> > coordinate;
//
//        int x, y;
//        pair<int, int> tok;
//
//        for (int i=0; i<n; i++) {
//            cin >> tok.first >> tok.second;
//            coordinate.push_back(tok);
//        }
        
        int result = 0;
        
        for (int i=0; i<n; i++) {
//            double angle = atan2(coordinate[i].second, coordinate[i].first) * 180 / 3.141592;
//            double r = sqrt(pow(coordinate[i].first, 2) + pow(coordinate[i].second, 2));
            int x,y;
            
            cin >> x >> y;
//            아래 파이 값을 3.14로 하면 제출했을때 점수가 마이너스 된다.
            double angle = atan2(y, x) * 180 / 3.141592;
            double r = sqrt(x*x + y*y);
            
            if(angle < 0)
                angle += 360;
//            아래는 각각의 크기인 18도에서 나누기2를 한 값인 9도를 더하면서 정방향으로 맞춘다. 따라서 20점의 점수는 -9~9 가 아닌
//            0~18이 되는 것이다.
            angle += 9;
//            아래는 360도 기준에서 18로 나누었을때 score 20개 중에 하나가 선택된다.
            if (angle >= 360) angle -= 360;
            int s = angle/18;
            
            
            if (r <= a) result += 50;
            else if (r >= b && r <= c) result += 3 * score[s];
            else if (r >= d && r <= e) result += 2 * score[s];
            else if (r <= e) result += score[s];
        }
        
        cout << "Case #" << t2-t1 << endl << result << endl;
        
    }
    
    return 0;
}

//아래 소스는 너무 지저분하다.
//
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//
//    int t1, t2;
//
//    cin >> t1;
//
//    t2 = t1;
//
//    while (t1–) {
//
//        int a,b,c,d,e;
//
//        cin >> a >> b >> c >> d >> e;
//
//        int n;
//
//        cin >> n;
//
////        아래 Codeground에서는 컴파일 에러가 나온다. 이는 '>>'를 '> >'로 바꾸어주면 해결된다.
//        vector<pair<int, int>> coordinate;
//
//        int x, y;
//        pair<int, int> tok;
//
//        for (int i=0; i<n; i++) {
//            cin >> tok.first >> tok.second;
//            coordinate.push_back(tok);
//        }
//
//        int score = 0;
//        int result = 0;
//
//        for (int i=0; i<coordinate.size(); i++) {
//            double angle = atan2(coordinate[i].first, coordinate[i].second) * 180 / 3.14;
//            double r = sqrt(pow(coordinate[i].first, 2) + pow(coordinate[i].second, 2));
//
//            if(angle < 9 && angle > -9)
//                score = 20;
//            else if(angle > 9 && angle <27)
//                score = 1;
//            else if(angle > 27 && angle < 45)
//                score = 18;
//            else if(angle > 45 && angle < 63)
//                score = 4;
//            else if(angle > 63 && angle < 81)
//                score = 13;
//            else if(angle > 81 && angle < 99)
//                score = 6;
//            else if(angle > 99 && angle < 117)
//                score = 10;
//            else if(angle > 117 && angle < 135)
//                score = 15;
//            else if(angle > 135 && angle < 153)
//                score = 2;
//            else if(angle > 153 && angle < 171)
//                score = 17;
//            else if(angle > 171)
//                score = 3;
//            else if(angle < -9 && angle > -27)
//                score = 5;
//            else if(angle < -27 && angle > -45)
//                score = 12;
//            else if(angle < -45 && angle > -63)
//                score = 9;
//            else if(angle < -63 && angle > -81)
//                score = 14;
//            else if(angle < -81 && angle > -99)
//                score = 11;
//            else if(angle < -99 && angle > -117)
//                score = 8;
//            else if(angle < -117 && angle > -135)
//                score = 16;
//            else if(angle < -135 && angle > -153)
//                score = 7;
//            else if(angle < -153 && angle > -171)
//                score = 19;
//            else if(angle < -171)
//                score = 3;
//
//            if(r < a)
//                score = 50;
//            else if(r > a && r < b)
//                score = score;
//            else if(r > b && r < c)
//                score = 3 * score;
//            else if(r > c && r < d)
//                score = score;
//            else if(r > d && r < e)
//                score = 2 * score;
//            else
//                score = 0;
//            
//            result += score;
//                
//        }
//        
//        out << "Case #" << t2-t1 << ends << result << ends;
//        
//    }
//    return 0;
//}
