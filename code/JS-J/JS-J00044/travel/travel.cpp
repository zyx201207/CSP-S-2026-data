#include<bits/stdc++.h>
using namespace std;
int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a, c;
    char b, d;
    if(s1.size() == 3) {
        a = stoi(s1.substr(0, 2));
        b = s1[2];
    } else {
        a = s1[0] - '0';
        b = s1[1];
    }
    if(s2.size() == 3) {
        c = stoi(s2.substr(0, 2));
        d = s2[2];
    } else {
        c = s2[0] - '0';
        d = s2[1];
    }
    if(b > d) swap(b, d);

    if(c1 == c2) cout << 1;
    else cout << 0;

    if(c1 == c2 && a == c) cout << 1;
    else cout << 0;

    if(c1 == c2 && a == c) {
        if(d <= 'C' || b >= 'D') cout << 1;
        else cout << 0;
    } else cout << 0;

    if(c1 == c2 && a == c) {
        if(b == 'D' || d == 'B' || (b == 'B' && d == 'C')) cout << 1;
        else cout << 0;
    } else cout << 0;
    return 0;
}
