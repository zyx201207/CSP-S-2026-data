#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5e5+10;
const ll M=1e5+10;
ll tot=0,Q,C,n,m,D;
ll W[N];
ll fans[510][510];
int son[N][21];
ll w[N][21];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>D>>Q;
    for(int i=1;i<=m;i++)
        cin>>W[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            ll x,y;
            cin>>x>>y;
            son[x][++son[x][0]]=i;
            w[x][son[x][0]]=y;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                fans[i][j]=6e15;
    int x,y,xx,yy;
    for(int fa=1;fa<=m;fa++)
    {
        for(int i=1;i<=son[fa][0];i++)
        {
            x=son[fa][i];
            for(int j=1;j<i;j++)
            {
                y=son[fa][j];
                fans[x][y]=fans[y][x]=min(fans[x][y],w[fa][i]+w[fa][j]);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i!=j&&j!=k&&k!=i)
                    fans[i][j]=min(fans[i][j],fans[i][k]+fans[k][j]);
            }
    }
    ll ans=0;
    while(Q--)
    {
        cin>>xx>>yy;
        ans=LONG_LONG_MAX;
        for(int i=1;i<=son[xx][0];i++)
        {
            x=son[xx][i];
            for(int j=1;j<=son[yy][0];j++)
            {
                y=son[yy][j];
                ans=min(ans,fans[x][y]+w[xx][i]+w[yy][j]+W[xx]+W[yy]);
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}