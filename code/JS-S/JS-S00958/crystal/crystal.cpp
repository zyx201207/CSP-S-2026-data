#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a);i <= (b);i++)
typedef long long ll;
typedef pair<int, int> pii;
const int Max = 5e5+5;
int n, ans = 1;
ll m, a[Max], sum[Max];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n)cin >> a[i];
    sort(a+1, a+n+1);
    rep(i, 1, n)sum[i] = sum[i-1]+a[i];
    rep(i, 1, n)
    {
        int l = 1, r = i, pos = i;
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(a[i]*(ll)(i-mid+1)-(sum[i]-sum[mid-1]) <= m)r = mid-1, pos = mid;
            else l = mid+1;
        }
        ans = max(ans, i-pos+1);
    }
    cout << ans;
    return 0;
}
