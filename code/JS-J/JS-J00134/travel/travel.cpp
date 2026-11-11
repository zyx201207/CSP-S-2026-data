#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , s1 , c2 , s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int w  = 0 , x = 0 , y = 0 , z = 0;
    char a = s1[0] , b = s1[1] , c = s2[0] , d = s2[1];
    if (c1 == c2) {
        w = 1;
        if (a == c && b == d) {
            x = 1;
            if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') || (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')) {
                y = 1;
                if (abs(int(s1[2] - s2[2])) == 1 || s1[2] == 'F' && s2[2] == 'D' || s1[2] == 'D' && s2[2] == 'F') {
                    z = 1;
                }
            }
        }
    }
    cout << w << x << y << z;
    return 0;
}
