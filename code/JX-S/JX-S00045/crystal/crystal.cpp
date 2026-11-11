#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int i,j;
    int n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ls=1,nw=0;
    int da=0;
    for(i=1;i<=n;i++)
    {
        nw+=(a[i]-a[i-1])*(i-ls);
        while(nw>m)
        {
            nw-=(a[i]-a[ls]);
            ls++;
        }
        da=max(da,i-ls+1);
    }
    cout<<da;
    return 0;
}
