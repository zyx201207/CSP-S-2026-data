#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 5e5 + 5;

int a[N],sum[N];

bool check(int x , int y , int m) {
    // return true;
    return a[y] * (y - x + 1) - (sum[y] - sum[x - 1]) <= m;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;i ++) {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int L = 0,R = i,mid;
        while(L + 1 < R) {
            mid = (L + R) >> 1;
            if(check(mid , i , m)) R = mid;
            else L = mid;
        }
        ans = max(ans , i - R + 1);
    }
    cout << ans << "\n";
    return 0;
}