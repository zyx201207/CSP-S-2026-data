#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,mxans=0,zz=0;
void aaaa(int x,int z,int l)
{
    if(x==m)
    {
        mxans=max(z,mxans);
        return;
    }
    if(zz>1e9) return;
    for(int i=l;i<=n+x-m+1;i++)
    {
        zz++;
        if(x==0) aaaa(x+1,a[i],i+1);
        else aaaa(x+1,z&a[i],i+1);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==0)
    {
        cout<<0;
        return 0;
    }
    if(m==1)
    {
        cout<<a[n];
        return 0;
    }
    if(m==2)
    {
        int ans=0;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[j]&a[i]);
        cout<<ans<<'\n';
        return 0;
    }
    if(m==n)
    {
        int z=a[1];
        for(int i=2;i<=n;i++) z=z&a[i];
        cout<<z<<'\n';
        return 0;
    }
    if(m==n-1)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int z;
            if(i==1)
            {
                z=a[2];
                for(int j=3;j<=n;j++) z=z&a[j];
                ans=max(ans,z);
            }
            else
            {
                z=a[1];
                for(int j=2;j<=n;j++) if(i!=j) z=z&a[j];
                ans=max(ans,z);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    aaaa(0,0,0);
    cout<<mxans<<'\n';
    return 0;
}
