#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int x;
        char c;
        cin >> x >> c;
        for (int j = 1; j <= x; j ++) {
            s += c;
        }
    }
    int l = 0, r = s.size() - 1;
    while (l <= r) {
        if (s[l] != s[r]) ans ++;
        l ++, r --;
    }
    cout << ans;
    return 0;
}
