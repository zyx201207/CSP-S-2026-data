#include <bits/stdc++.h>
#define ONLINE(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define int long long
using namespace std;

using int128 = __int128_t;

inline int128 read() {
    __int128 f = 1, res = 0, c;
    for (; (c < '0' || c > '9') && c != EOF; c = getchar_unlocked()) if (c == '-') f = -1;
    for (; (c >= '0' && c <= '9'); c = getchar_unlocked()) res = res * 10 + c - '0';
    return f * res;
}

inline void write(int128 x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ONLINE(crystal);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a.begin() + 1, a.end());

    int ans = 1;

    queue<int> q;
    int need = 0;

    q.push(a[1]);

    for (int i = 2; i <= n; i++) {
        int diff = a[i] - a[i - 1];
        need += q.size() * diff;

        q.push(a[i]);

        while (need > m) {
            need -= a[i] - q.front();
            q.pop();
        }

        ans = max(ans, (int) q.size());
    }

    cout << ans << "\n";
    return 0;
}
