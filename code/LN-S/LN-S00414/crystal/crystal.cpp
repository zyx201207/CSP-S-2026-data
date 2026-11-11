#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],s[500005];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
    {
        s[i]=a[i+1]-a[i];
    }
    int mx=0;
    int k=0;
    for(int i=1,j=1;j<n;j++)
    {
        k+=s[j]*(j-i+1);
        if(k>m)
        {
            while(k>m)
            {
                k-=(a[j+1]-a[i]);
                i++;
            }
        }
        mx=max(mx,j-i+1);
    }
    cout<<mx+1;
    return 0;
}
