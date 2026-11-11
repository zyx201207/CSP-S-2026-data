#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],sum[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        while(x*(i-l+1)-sum[i]+sum[l-1]>m) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
