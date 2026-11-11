#include <bits/stdc++.h>

// #define int long long

using namespace std;

const int N = 2e5 + 10;


int n, m;
int a[N];

bool cmp(int q, int h){
    return q > h;
}

int ans = 0;

void dfs(int x, int d, int now) {
    if (d == m) {
        ans = max(ans, now);
        return;
    }
    for (int i = x + 1; i <= n; ++i) {
        dfs(i, d + 1, now & a[i]);
        dfs(i, d, now);
    }
}

//void solve_dp() {
//    for (int i = 1; i <= n; i++) {
//        int mt = m      ;
//        for (int j = 1; j < i; j++) {
//
//        }
//    }
//}

signed main() {

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);

    cin >> n >> m;

    int ansx = a[1];

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (n > 1) ansx &= a[i];
    }

    if (n == m) {
        cout << ansx << '\n';
        return 0;
    }

    if (n <= 20) {
        dfs(1, 1, a[1]);
        dfs(1, 0, (1 << 30) - 1);
        cout << ans << '\n';
        return 0;
    }

//    if (n <= 2000) {
//        solve_dp();
//    }

     sort(a + 1, a + 1 + n, cmp);

	 // for (int i = 1; i <= n; i++) {
     //     cerr << a[i] << ' ';
     // }cerr << '\n';

     int ans = a[1];
	
     for (int i = 2; i <= m; ++i) {
         ans = ans & a[i];
     }

     cout << ans << '\n';

    return 0;
}
