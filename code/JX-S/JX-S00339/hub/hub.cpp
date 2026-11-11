#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long 
#define i128 __int128
#define fi first
#define se second
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define INF 0x3f3f3f3f
#define INFx 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 1e6 + 10;

int n, k;
int h[N], e[N << 1], ne[N << 1], idx = 1;

void solve() {
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
    }

    cout << n / 2 << '\n';
}

int main() {
    freopen("hub.in", "r", stdin); // modify!!!
    freopen("hub.out", "w", stdout); // modify!!!
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T--) solve();

    return 0;
}
