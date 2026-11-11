#include<bits/stdc++.h>
using namespace std;
int c,n,d,q,m,w[500001],k[501],a[501][500001],t[501][500001],x,y,b[501];
long long ans;
void dfs(int s,long long p)
{
    if(s==y)
    {
        ans=min(ans,p);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!b[i])
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==s)
                {
                    p+=t[i][j];
                    for(int l=1;l<=k[i];l++)
                    {
                        if(a[i][l]!=s)
                        {
                            b[i]=1;
                            dfs(a[i][l],p+t[i][l]);
                            b[i]=0;
                        }
                    }
                    p-=t[i][j];
                }
            }
        }
    }
    return;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];

        }
    }
    for(int i=0;i<q;i++)
    {
        cin>>x>>y;
        ans=9e18;
        dfs(x,0);
        cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}
