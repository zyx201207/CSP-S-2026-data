#include <bits/stdc++.h>
using namespace std;

int n, L, cnt = 0;
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int len;
        char letter;
        cin >> len >> letter;
        L += len;
        for (int j = 1; j <= len; j++) s += letter;
    }
    string t = s;
    reverse(t.begin(), t.end());
    for (int i = 0; i <= L / 2 - 1; i++) if (s[i] != t[i]) cnt++;
    cout << cnt;

    return 0;
}
