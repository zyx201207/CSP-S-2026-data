#include<bits/stdc++.h>
using namespace std;
int c, x;
int scm, sxm;
string sc, sx;
int finds(char c){
    if(c == 'D' || c == 'F')return 2;
    return 1;
}
bool p1(){
    if(c == x)return true;
    return false;
}
bool p2(){
    if(p1() && scm == sxm)return true;
    return false;
}
bool p3(){
    if(p2() && finds(sc[2]) == finds(sx[2]))return true;
    return false;
}
bool p4(){
    if(p3() && (sx[2] == 'D' || sc[2] == 'D' || abs(sx[2] - sc[2]) == 1))return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c >> sc >> x >> sx;
    scm = (sc[0]-'0')*10+sc[1]-'0';
    sxm = (sx[0]-'0')*10+sx[1]-'0';
    cout << p1() << p2() << p3() << p4();
    return 0;
}
