#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int a, b;
int c, d;
bool check(string s) {
    char ch = s[2];
    if (ch == 'F' || ch == 'D') return 0;
    return 1;
}
bool check2() {
    char ch1 = s1[2];
    char ch2 = s2[2];
    if (abs(ch1 - ch2) == 1) return 1;
    return 0;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for (int i = c1.size() - 1; i > 0; i--) {
        a *= 10;
        a += c1[i] - '0';
        b *= 10;
        b += c2[i] - '0';
    }
    for (int i = s1.size() - 2; i > 0; i--) {
        c *= 10;
        c += s1[i] - '0';
        d *= 10;
        d += s2[i] - '0';
    }
    if (a == b) cout << 1;
    else cout << 0;
    if (a == b && c == d) cout << 1;
    else cout << 0;
    if (a == b && c == d && check(s1) == check(s2)) cout << 1;
    else cout << 0;
    if (a == b && c == d && check(s1) == check(s2) && check2()) cout << 1;
    else cout << 0;
    return 0;
}
// red
