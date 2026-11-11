#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); i ++ )
#define repf(i, a, b) for(int i = (a); i >= (b); i -- )
typedef long long ll;
const int N = 5e5 + 10;
ll a[N]; ll pre[N]; ll m;
bool check(int x, int y)
{
    ll len = y - x + 1;
    ll nd = len*a[y] - (pre[y] - pre[x-1]);
    return m >= nd;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    int n; cin >> n >> m; rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, n)pre[i]=pre[i-1]+a[i];
    int ans = 0;
    rep(i,1,n)
    {
        int l = 1, r = i, best = -1;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(check(mid, i)) r = mid - 1, best = mid;
            else l = mid + 1;
        }
        ans = max(ans, i-best+1);
    }
    cout << ans << '\n';
    return 0;
}
