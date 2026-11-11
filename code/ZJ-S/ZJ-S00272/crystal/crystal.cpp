#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500005;

int n,m;
int a[maxn];
int sum[maxn];
int l = 1,r = 1;
int ans;

signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    while(r <= n)
    {
        while(a[r] * (r - l + 1) > sum[r] - sum[l - 1] + m)
        {
            l++;
        }
        ans = max(ans,r - l + 1);
        r++;
    }
    cout<<ans<<"\n";
}