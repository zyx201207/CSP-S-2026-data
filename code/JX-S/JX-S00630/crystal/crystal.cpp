#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500100],cha[500100],zhui[500100],r,l,temm,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) cha[i]=a[i]-a[i-1];
    l=1;
    r=1;
    while(l<=r and r<=n)
    {
        if(temm+cha[r+1]*(r-l+1)<=m)
        {
            if(r==n) break;
            temm+=cha[r+1]*(r-l+1);
            r++;
            ans=max(ans,r-l+1);
        }
        else
        {
            temm-=a[r]-a[l];
            l++;
        }
    }
    cout<<ans;
    return 0;
}
