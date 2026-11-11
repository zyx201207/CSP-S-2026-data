#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x,y,ans=0;
int vis[505],g=0;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--)
    {
        memset(vis,0,sizeof vis);
        cin>>x>>y;
        int ans=0,d1=-1,d2=-1;
        bool f=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x)d1=i;
                if(a[i][j]==y)d2=i;
                if(d1!=-1&&d2!=-1){
                    f=1;
                    break;

                }
            }
            if(f)break;
        }
        if(d1==d2)
        {
            cout<<w[x]+w[y]+t[x][x]+t[x][y]<<endl;
            continue;
        }
        for(int i=1;i<=k[i];i++)
        {
            vis[a[d1][i]]++;
            vis[a[d2][i]]++;
        }
        for(int i=1;i<=m;i++)
            if(vis[i]==2)g=i;
        ans=w[x]+w[y]+t[x][x]+t[x][g]+t[g][g]+t[g][y];
        cout<<ans<<endl;
    }

    return 0;
}
