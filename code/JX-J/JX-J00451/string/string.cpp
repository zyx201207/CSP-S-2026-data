#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ll n, a;
    cin >> n;
    char c;
    ll ans = 0;
    for (ll i = 0; i < n; i ++) {
        cin >> a >> c;
        ans += a;
        for (ll j = i; j <= a; j ++) {
            s[j] = c;
        }
    }
    bool flag = 0;
    for (ll i = 0; i < ans; i ++) {
        if (s[i] == c) {
            flag = 1;
        } else{
            flag = 0;
            break;
        }
    }
    ll cnt = 0;
    cout << 0;
    return 0;
}
