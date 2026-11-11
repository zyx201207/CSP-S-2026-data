#include<bits/stdc++.h>
using namespace std;
string c1, c2, x1, x2;
int a, b, c, d;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> c2 >> x1 >> x2;
    if(c1 == x1)a = 1;
    int q1 = c2[0] - '0', q2 = c2[1] - '0', p1 = x2[0] - '0', p2 = x2[1] - '0';
    if(q1 == p1&&q2 == p2&& a == 1)b = 1;
    char q3 = c2[2] , p3 = x2[2];
    if(abs(q3 - p3) <= 2&&b == 1)c = 1;
    if(abs(q3 - p3) == 1&&c == 1)d = 1;
    ans += a + '0';
    ans += b + '0';
    ans += c + '0';
    ans += d + '0';
    cout << ans;

    return 0;
}
