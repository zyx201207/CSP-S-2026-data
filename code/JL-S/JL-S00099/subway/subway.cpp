#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,inf=0x3f3f3f3f;
int c,n,m,d_,q,k,w[N],a[N],t[N],d[N][N],x,y;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d_>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
            d[i][j]=inf;
    }
    for(int l=1;l<=n;l++)
    {
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>a[i]>>t[i];
            for(int j=1;j<i;j++)
                d[a[j]][a[i]]=d[a[i]][a[j]]=min(d[a[j]][a[i]],t[j]+t[i]);
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++)
            for(int k=1;k<=m;k++)
            {
                if(k==i||k==j)
                    continue;
                d[i][j]=min(d[i][j],d[i][k]+d[j][k]);
            }
    while(q--)
    {
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        cout<<d[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
