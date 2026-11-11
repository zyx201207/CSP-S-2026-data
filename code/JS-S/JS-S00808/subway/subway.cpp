#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][5005],t[505][5005],x,y,ans=1e12,s[505],p,z[505],b,f[505],l;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
    }
    while(q--)
    {
        ans=1e12;
        cin>>x>>y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==x)s[++p]=i;
                if(a[i][j]==y)z[++b]=i;
            }
        for(int i=1;i<=p;i++)
            for(int j=1;j<=b;j++)if(s[i]==z[j])f[++l]=s[i];
        for(int i=1;i<=l;i++)
        {
            long long r,v,sum=0;
            for(int j=1;j<=k[f[i]];j++)
            {
                if(a[i][j]==x)r=t[i][j];
                if(a[i][j]==y)v=t[i][j];
            }
            sum=r+v;
            ans=min(ans,sum);
        }
        ans+=w[x]+w[y];
        cout<<ans<<endl;
    }
    return 0;
}
