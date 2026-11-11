#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i =1 ;i <= n;i ++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i =1 ;i <= n;i ++)
        sum[i] = sum[i - 1] + a[i];
    int ans = 0;
    for(int l = 1,r = 1;r <= n;)
    {
        while(r <= n && a[r] * (r - l) - (sum[r - 1] - sum[l - 1]) <= m) r++;
        ans = max(ans,r - l);
        while(l <= r && a[r] * (r - l) - (sum[r - 1] - sum[l - 1]) > m) l++;
    }   
    cout<<ans<<endl;
    return 0; 
}