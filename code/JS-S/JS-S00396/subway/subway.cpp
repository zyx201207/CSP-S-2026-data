#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],dis[5005][5005],k,a[500005],t[500005],x,y;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
        for(int l=1;l<k;l++){
            for(int r=l+1;r<=k;r++){
                dis[a[l]][a[r]]=dis[a[r]][a[l]]=min(dis[a[l]][a[r]],t[l]+t[r]);
            }
        }
    }
    for(int i=1;i<m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            for(int l=1;l<=m;l++)
            {
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][l]+dis[l][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<endl;
    }
    return 0;
}
