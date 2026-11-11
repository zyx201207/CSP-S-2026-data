#include <iostream>
#include <string>
using namespace std;
int n, a[100010];
char c[100010];
string s;
long long ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++) s.push_back(c[i]);
    }

    for (int i = 0, j = s.size() - 1; i < s.size() && j >= i; i++, j--) {
        if (s[i] != s[j]) ans++;
    }
    cout << ans;
    return 0;
}

