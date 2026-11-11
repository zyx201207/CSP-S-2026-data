#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
int x[MAXN];
int dis[5050][5050],m[5050][5050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        memset(dis,0x3f,sizeof(dis));
        memset(m,0,sizeof(m));
        for(int i=1;i<n;i++) dis[i][i+1]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(x[j]-x[i]<=d) dis[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                for(int k=i;k<=j;k++)
                {
                    if(dis[i][k]+dis[k][j]==dis[i][j]) m[i][j]++;
                    else if(dis[i][k]+dis[k][j]<dis[i][j]) m[i][j]=1,dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(m[i][j]==2){ ans++;}
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
