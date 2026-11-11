#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll read() {
    ll x = getchar_unlocked(), res = 0, flag = 1;
    for (; x != EOF && (x < '0' || x > '9'); x = getchar_unlocked())
        if (x == '-')
            flag = -1;
    for (; x >= '0' && x <= '9'; x = getchar_unlocked())
        res = res * 10 + x - '0';
    return res * flag;
}
ll getfont(char a) {
    if (a >= 'A' && a <= 'C')   return 1;
    return 0;
}
bool work(string a, string b) {
    if (b[2] - a[2] == 1)   return true;
    return false;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ll c1 = read(), c2;
    string s1, s2;
    cin >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << "1";
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << "1";
            if (getfont(s1[2]) == getfont(s2[2])){
                cout << "1";
                if (work(s1, s2))
                    cout << "1";
                else    cout << "0";
            } else
                cout << "00";
        } else
            cout << "000";
    }else
        cout << "0000";
    return 0;
}