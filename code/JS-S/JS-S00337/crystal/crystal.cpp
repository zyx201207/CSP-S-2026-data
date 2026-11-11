// 二分 前缀和 橙～黄
#include <bits/stdc++.h>
using namespace std;

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

#define int long long
const int N = 5e5+5;
int n, m, a[N];
int sum[N], mx;

bool check(int i, int p)
{
    return (i - p + 1) * a[i] - (sum[i] - sum[p - 1]) <= m;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(i, mid)) {   // 可行，于是往左移动
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        mx = max(mx, i - l + 1);
    }
    
    cout << mx;

    return 0;
}