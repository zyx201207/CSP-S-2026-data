#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s;
    int n;
    cin >> n;
    while (n--) {
        ll a;
        char c;
        cin >> a >> c;
        for (ll i = 1; i <= a; i++) s += c;
    }
    ll ans = 0, l = s.length();
    for (ll i = 0; i < l / 2; i++)
        if (s[i] != s[l - i - 1]) ans++;
    cout << ans;
    return 0;
}
