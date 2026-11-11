#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000006]={};
int vis[300][300][10]={};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    long long ans=0;
    if(c==0)
    {
        while(t--)
        {
            memset(x,0,sizeof(x));
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>x[i];
            long long cont=0;
            for(int i=1;i<=n;i++){
                if(x[1]+d>x[i]&&x[1]+d<x[i+1]) cont=i;
            }
            for(int i=1;i<=n;i++)
            {
                if(i==cont) continue;
                for(int j=i;i<=n;i++)
                {
                    if(x[j]-x[i]<=d||(x[j]-x[i])%d==0)
                    {
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    while(t--)
    {
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                if(x[j]-x[i]<=d) vis[i][j][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                for(int l=1;l<10;i++)
                    for(int k=i+1;k<j;k++)
                        vis[i][j][l]=max(vis[i][j][l],vis[i][k][l-1]+vis[k][j][1]);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                for(int l=1;l<10;l++){
                    if(vis[i][j][l]==2&&vis[i][j][l-1]==0) ans++;
                }
        cout<<ans<<endl;
    }
    return 0;
}
