#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, n1, n2, ans;
char a, b;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        ans += "1";
        n1 = s1.substr(0, 2);
        n2 = s2.substr(0, 2);
        if (n1 == n2){
            ans += "1";
            a = s1[2];
            b = s2[2];
            if ('A' <= a && a <= 'C' && 'A' <= b && b <= 'C'){
                ans += "1";
                if (abs(a - b) == 1)
                    ans += "1";
                else ans += "0";}
            else if (('D' == a || a == 'F') && ('D' == b || b == 'F')){
                ans += "1";
                if (abs(a - b) == 1)
                    ans += "1";
                else ans += "0";}
            else ans += "00";}
        else ans += "000";}
    else ans = "0000";
    cout << ans;
    return 0;}
