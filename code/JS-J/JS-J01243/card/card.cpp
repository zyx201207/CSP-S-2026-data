#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans[500005];
int a[500005];
int f[500005];
int b[500005];
long long c[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    b[a[n]]=n;
    c[f[n]]++;
    for(int i=n-1;i>=1;i--)
    {
        if(b[a[i]]!=0) f[i]=f[b[a[i]]];
        c[f[i]]++;
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=0)
        {
            ans[a[i]]+=c[i];
            c[f[i+1]]+=c[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}