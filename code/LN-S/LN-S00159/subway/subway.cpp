#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[100001];
long long a[501][501];
long long dis[501][501];
long long ai[501][1001];
long long t[501][1001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=500;i++)
        for(int j=1;j<=500;j++)
        a[i][j]=1e9;

    for(long long i=1;i<=m;i++)
        cin>>w[i];
            for(long long i=1;i<=n;i++)
            {
                long long k;
                cin>>k;
                for(long long j=1;j<=k;j++)
                    cin>>ai[i][j]>>t[i][j];

                for(long long j=1;j<=k;j++)
                {
                    for(long long l=1;l<=k;l++)
                    {
                        if(j==l)
                            continue;
                        a[ai[i][j]][ai[i][l]]=min(t[i][j]+t[i][l],a[ai[i][j]][ai[i][l]]);
                        a[ai[i][l]][ai[i][j]]=min(t[i][j]+t[i][l],a[ai[i][l]][ai[i][j]]);
                    }
                }


            }
            for(long long k=1;k<=m;k++)
                for(long long i=1;i<=m;i++)
                for(long long j=1;j<=m;j++)
                    {
                        if(i==j)
                            continue;
                        a[i][j]=a[j][i]=min(a[i][k]+a[k][j],a[i][j]);
            }
            for(long long i=1;i<=q;i++)
            {
                long long x,y;
                cin>>x>>y;
                cout<<a[x][y]+w[x]+w[y]<<"\n";
            }


return 0;
}
//I LOVE CCF 妈妈我上电视了！
