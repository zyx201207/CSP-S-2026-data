#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        s += string(a, c);
    }
    long long ans = 0;
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
