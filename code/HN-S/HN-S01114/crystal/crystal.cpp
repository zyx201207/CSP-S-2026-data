#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int T;
int n,m,k,a[500005],b[500005];
bool check(int l,int r)
{
    return (r - l + 1) * a[r] - (b[r] - b[l - 1]) <= m;
}
void solve()
{
    int ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i ++)b[i] = b[i - 1] + a[i];
    for(int i = 1;i <= n;i ++)
    {
        int L = 1,R = i;
        while(L < R)
        {
            int mid = (L + R) >> 1;
            if(check(mid,i))R = mid;
            else L = mid + 1;
        }
        ans = max(ans,i - L + 1);
    }
    cout << ans;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T = 1;
    while(T --)solve();
}
/*
idea:14:35
solved:14:40
expected:100pts
Oct31==Dec25?
*/
