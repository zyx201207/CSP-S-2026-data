#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define gc getchar_unlocked
#define readT int

inline readT rd() {
    readT x = 0; int ch = gc(), f = 1;
    for (; ! isdigit(ch); ch = gc()) {if (ch == '-') {f = -1;}}
    for (; isdigit(ch); ch = gc()) {x = (x << 3) + (x << 1) + (ch ^ 48);}
    return x * f;
}


inline void sol() {
    string s1, s2, c1, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    
    if (s1 != s2) {
        puts("0000");
        return;
    }
    cout << 1;

    if (c1[0] != c2[0] || c1[1] != c2[1]) {
        puts("000");
        return;
    }

    cout << 1;
    if ((c2[2] >= 'A' && c2[2] <= 'C' && c1[2] >='D') || (c1[2] <= 'C' && c2[2] >= 'D')) {
        puts("00");
        return;
    }
    else cout << 1;

    if (c2[2] - c1[2] == -1 || c2[2] - c1[2] == 1) {
        cout << 1;
    }
    else cout << 0;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int qwq = 1;
    // qwq = rd();
    while (qwq --) {
        sol();
    }

    return 0;
}