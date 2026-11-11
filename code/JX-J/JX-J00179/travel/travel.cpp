#include <iostream>
using namespace std;
int main(){
    int c1, c2;
    char  ct1 = 0, ct2 = 0, s1[4] = {0}, s2[4] = {0}, output[4] = {0};
    freopen("travel.in", "r", stdin);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        output[0] = 1;}
    if (s1[0] + s1[1] == s2[0] + s2[1] && output[0]){
        output[1] = 1;
        if (s1[2] - 0 < 68 && s2[2] - 0 < 68 ){
            output[2] = 1;}
        if (s1[2] - 0 > 67 && s2[2] - 0 > 67){
            output[2] = 1;}}
    if (output[2] && abs((s1[2] - 0) - (s2[2] - 0)) == 1){
            output[3] = 1;}
    int a = output[0], b = output[1], c = output[2], d = output[3];
    freopen("travel.ans", "w", stdout);
    cout << a << b << c << d;
}
