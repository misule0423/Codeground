//
//  main.cpp
//  easy_7
//
//  Created by 이민석 on 2016. 9. 25..
//  Copyright © 2016년 Roop. All rights reserved.
//

//아래는 백준이 짠 소스이다.
#include <cstdio>
#include <cstring>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int a[1000][1000];
bool c[1000][1000];
// 0 = 아래, 1 = 위, 2 = 오른쪽, 3 = 왼쪽
int change_dir(int dir, int mirror) {
    if (mirror == 1) { // 좌측 하단으로 45도
        // 0 -> 3, 1 -> 2, 2 -> 1, 3 -> 0
        return 3-dir;
    } else { // 우측 하단으로 45도
        // 0 -> 2, 1 -> 3, 2 -> 0, 3 -> 1
        return (dir+2)%4;
    }
}
int main() {
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        int n;
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%1d",&a[i][j]);
                c[i][j] = false;
            }
        }
        int row, col, dir;
        row = 0;
        col = 0;
        dir = 2;
        // dir
        // 0 = 아래, 1 = 위, 2 = 오른쪽, 3 = 왼쪽
        while (0 <= row && row < n && 0 <= col && col < n) {
            if (a[row][col] != 0) {
                c[row][col] = true;
                dir = change_dir(dir, a[row][col]);
            }
            row += dx[dir];
            col += dy[dir];
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (c[i][j]) {
                    ans += 1;
                }
            }
        }
        printf("Case #%d\n",tc);
        printf("%d\n",ans);
    }
    
    return 0;
}

//실제로 내가 짠 소스이다. 각각의 경우마다 모든 것을 할당해주었다. 왜냐하면 12개밖에 되지 않기 때문이다.
//
//#include <iostream>
//using namespace std;
//
//int main(int argc, const char * argv[]) {
//    
//    int tc;
//    
//    cin >> tc;
//    
//    for (int testCase=1; testCase<=tc; testCase++) {
//        
//        int N;
//        
//        cin >> N;
//        
//        char maze[1002][1002];
//        bool visit[1002][1002];
//        
//        for (int i=0; i<1002; i++) {
//            for (int j=0; j<1002; j++) {
//                maze[i][j] = '0';
//                visit[i][j] = false;
//            }
//        }
//        
//        char line[1002];
//        
//        for (int i=0; i<N; i++) {
//            
//            cin >> line;
//            
//            for (int j=0; j<N; j++) {
//                maze[i+1][j+1] = line[j];
//            }
//            
//        }
//        
//        
//        //    for (int i=1; i<N+1; i++) {
//        //        for (int j=1; j<N+1; j++) {
//        //            cout << maze[i][j] << " ";
//        //        }
//        //        cout << endl;
//        //    }
//        
//        char status = 'R';
//        int x = 1, y = 1;
//        
//        while (1) {
//            if(x == 0 || y == 0 || x > N || y > N){
//                break;
//            } else if(status == 'L' && maze[x][y] == '1'){
//                status = 'D';
//                visit[x][y] = true;
//                x++;
//            } else if(status == 'R' && maze[x][y] == '1'){
//                status = 'U';
//                visit[x][y] = true;
//                x--;
//            } else if(status == 'U' && maze[x][y] == '1'){
//                status = 'R';
//                visit[x][y] = true;
//                y++;
//            } else if(status == 'D' && maze[x][y] == '1'){      //
//                status = 'L';
//                visit[x][y] = true;
//                y--;
//            } else if(status == 'R' && maze[x][y] == '2'){
//                status = 'D';
//                visit[x][y] = true;
//                x++;
//            } else if(status == 'L' && maze[x][y] == '2'){      //
//                status = 'U';
//                visit[x][y] = true;
//                x--;
//            } else if(status == 'U' && maze[x][y] == '2'){
//                status = 'L';
//                visit[x][y] = true;
//                y--;
//            } else if(status == 'D' && maze[x][y] == '2'){
//                status = 'R';
//                visit[x][y] = true;
//                y++;
//            } else if(status == 'L' && maze[x][y] == '0'){
//                y--;
//            } else if(status == 'R' && maze[x][y] == '0'){
//                y++;
//            } else if(status == 'U' && maze[x][y] == '0'){
//                x--;
//            } else if(status == 'D' && maze[x][y] == '0'){
//                x++;
//            }
//        }
//        
//        int result = 0;
//        
//        for (int i=0; i<1002; i++) {
//            for (int j=0; j<1002; j++) {
//                if(visit[i][j] == true)
//                    result ++;
//            }
//        }
//        
//        cout << "Case #" << testCase << endl << result << endl;
//        
//    }
//    
//    return 0;
//}
