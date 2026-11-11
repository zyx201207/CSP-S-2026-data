#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],q,w,e,t[500005],f[3001][3001],n,m,k[3001][3001],d;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>q>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++)
    {
        cin>>t[i];
    }
    for(long long i=1;i<=3000;i++)
    {
        for(long long j=1;j<=3000;j++)
        {

            if(i!=j) f[i][j]=1000000001;
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cin>>w;
        for(long long j=1;j<=w;j++)
        {
            cin>>a[j];
            cin>>b[j];
        }
        for(long long j=1;j<w;j++)
        {
            for(long long k=j+1;k<=w;k++)
            {
                f[a[j]][a[k]]=min(f[a[j]][a[k]],b[k]+b[j]);
                f[a[k]][a[j]]=min(f[a[k]][a[j]],b[j]+b[k]);
            }
        }
    }
    for(long long i=1;i<=m;i++)
    {
        for(long long j=1;j<=m;j++)
        {
            for(long long k=1;k<=m;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(long long i=1;i<=q;i++)
    {
        cin>>w>>e;
        cout<<(f[w][e]+t[w]+t[e])<<"\n";
    }

    return 0;    
}