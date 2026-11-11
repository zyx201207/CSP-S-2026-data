#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c1, c2;
string s1, s2;
signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    int p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    int pos1 = s1[2] - 'A' + 1;
    int pos2 = s2[2] - 'A' + 1;
    //cout << c1 << " " << p1 << " " << pos1 << " " << c2 << " " << p2 << " " << pos2 << "\n";
    cout << (c1 == c2);
    cout << ((p1 == p2) && (c1 == c2));
    cout << (((pos1 <= 3 && pos2 <= 3) || ( pos1 > 3 && pos2 > 3)) && (c1 == c2) && (p1 == p2));
    cout << ((c1 == c2) && (p1 == p2) && abs(pos1 - pos2) == 1 && ((pos1 <= 3 && pos2 <= 3) || ( pos1 > 3 && pos2 > 3)));
    return 0;
}
//2026 csp j/s rp ++;