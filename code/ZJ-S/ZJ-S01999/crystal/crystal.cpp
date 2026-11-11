// tuxiaolai
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 10;

int n;
ll m, a[N];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll res = 0, t = 0, it = 1;
    for (ll i = 1; i <= n; i++) {
        // s[i] = s[i - 1] + a[i];
        t += (i - it) * (a[i] - a[i - 1]);
        while (t > m) {
            t -= a[i] - a[it++];
        }
        res = max(res, i - it + 1);
    }

    cout << res << '\n';


    return 0;
} // g++ crystal.cpp -o crystal -O2 -std=c++14 -Wall -Wextra -Wshadow -Wconversion -Wl,--stack=512000000