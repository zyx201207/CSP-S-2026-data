#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    int a,b;
    string p = s1.substr(0,1),t = s2.substr(0,1);
    if (p[0] == '0'){
        a = p[1] - '0';
    }
    else{
        a = p[1] - '0' + 10;
    }
    if (t[0] == '0'){
        b = p[1] - '0';
    }
    else{
        b = p[1] - '0' + 10;
    }
    if (a == b){
        cout << 1;
        if ('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C' || 'D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F'){
            if ('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C'){
                if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]){
                    cout << 1;
                }
                else{
                    cout << 0;
                }
            }
            else{
                cout << 1;
            }
        }
        else{
            cout << 0;
        }
    }
    else{
        cout << 0;
    }
}
//• 两张车票对应的座位是否在同一节车厢;
//• 两张车票对应的座位是否在同一节车厢的同一排;
//• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
//• 两张车票对应的座位是否相邻。
//【输入格式】
//从文件 travel.in 中读入数据。
//输入的第一行包含四个字符串 c 1 , s 1 , c 2 , s 2 ,分别表示小 R 的车票上的车厢号、座位
//号,以及小 X 的车票上的车厢号、座位号。
//【输出格式】
//输出到文件 travel.out 中。
//第 2 页
//共 13 页
