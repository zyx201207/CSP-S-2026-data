#include <bits/stdc++.h>
using namespace std;

char ch;
string s;
long long n, m, r, l, cnt;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m >> ch;
        for (int j = 1; j <= m; ++j) {
            s += ch;
        }
    }
    l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] != s[r]) {
            cnt++;
        }
        l++;
        r--;
    }
    cout << cnt << endl;
    return 0;
}