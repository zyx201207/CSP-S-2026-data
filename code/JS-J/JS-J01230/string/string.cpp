#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++) {
            s += c;
        }
    }
    // cout << s << '\n';
    long long ans = 0;
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) {
            ans++;
        }
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}