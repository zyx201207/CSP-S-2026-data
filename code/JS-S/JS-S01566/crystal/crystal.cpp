#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 9;

int n , m;
int a[N] , sum[N];
int get(int x) {
    int l = 1 , r = x , ans = 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (mid * a[x] - sum[x] + sum[x - mid] <= m) {
            l = mid + 1;
            ans = l;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for (int i = 1;i <= n;i ++)  sum[i] = sum[i - 1] + a[i];

    int ans = 1;
    for (int i = 1;i <= n;i ++) {
        int cur = get(i);
        ans = max(cur - 1 , ans);
    }
    cout << ans << endl;
}

signed main()  {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(0);  cin.tie(0);

    int T = 1;
    //cin >> T;
    while (T--)  {
        solve();
    }
    return 0;
}

