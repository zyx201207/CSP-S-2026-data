#include<bits/stdc++.h>
using namespace std;
char x, y;
int a1, b1, a2, b2;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    a1 = ((c1[0] - '0') * 10) + (c1[1] - '0');
    b1 = ((s1[0] - '0') * 10) + (s1[1] - '0');
    a2 = ((c2[0] - '0') * 10) + (c2[1] - '0');
    b2 = ((s2[0] - '0') * 10) + (s2[1] - '0');
    x = s1[2] - 'A' + 1;
    y = s2[2] - 'A' + 1;
    if(a1 == a2) cout << "1";
    else cout << "0";
    if(a1 == a2 && b1 == b2) cout << "1";
    else cout << "0";
    if(a1 == a2 && b1 == b2 && ((x <= 3 && y <= 3) || (x > 3 && y > 3))) cout << "1";
    else cout << "0";
    if(a1 == a2 && b1 == b2 && ((x <= 3 && y <= 3) || (x > 3 && y > 3)) && abs(x - y) == 1) cout << "1";
    else cout << "0";

    return 0;
}
