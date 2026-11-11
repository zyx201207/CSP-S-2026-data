#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int c_1 = 0, s_1 = 0, c_2 = 0, s_2 = 0;
    for(int i = 0; i < 2; i++) {
        c_1 += (c1[i] - '0') * pow(10, 1-i);
        c_2 += (c2[i] - '0') * pow(10, 1-i);
        s_1 += (s1[i] - '0') * pow(10, 1-i);
        s_2 += (s2[i] - '0') * pow(10, 1-i);
    }
    bool f1 = false;
    if(c_1 == c_2) {
        cout << 1;
        f1 = true;
    } else {
        cout << 0;
    }
    bool f2 = false;
    if(f1 && (s_1 == s_2)) {
        cout << 1;
        f2 == true;
    } else {
        cout << 0;
    }
    char a, b;
    a = s1[2];
    b = s2[2];
    bool f4 = false;
    if(f1 && f2 && (a >= 'A' && a <= 'C' && b >= 'A' && b <= 'C' || a >= 'D' && a <= 'F' && b >= 'D' && b <= 'F')) {
        cout << 1;
        f4 = true;
    } else {
        cout << 0;
    }
    if (f4 && (b == a + 1 || b == a - 1)) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
