#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e4+5;
int c,n,m,d,q;
ll w[MAXN];
int k[MAXN];
ll a[502][MAXN];
ll t[502][MAXN];
ll uv[502][502];
ll r[MAXN][502];
int vis[503];
ll cnt=LLONG_MAX;
void dfs(int e,ll s,int l)
{
    if(r[e][l])
    {
        cnt=min(cnt,s+t[l][e]);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==l)continue;
        if(uv[l][i]!=0x3f3f3f3f3f3f3f3f&&!vis[i])
        {
            vis[l]=1;
            dfs(e,s+uv[l][i],i);
            vis[l]=0;
        }
    }
}
void sol()
{
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
            cin>>a[i][j];
            r[a[i][j]][i]=1;
            cin>>t[i][j];
        }
    }
    memset(uv,0x3f,sizeof(uv));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int x=1;x<=k[i];x++)
            {
                for(int y=1;y<=k[j];y++)
                {
                    if(a[i][x]==a[j][y])
                    {
                        uv[i][j]=uv[i][j]=min(uv[i][j],t[i][x]+t[j][y]);
                    }
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        ll ans=w[x]+w[y];
        vector<int>ttt;
        for(int i=1;i<=n;i++)
        {
            if(r[x][i]==0)continue;
            if(r[y][i])
            {
                ans+=t[i][x]+t[i][y];
                cout<<ans;
                return;
            }
            ttt.push_back(i);
        }
        for(int i=0;i<ttt.size();i++)
        {
            vis[ttt[i]]=1;
            dfs(y,t[ttt[i]][x],ttt[i]);
            vis[ttt[i]]=0;
        }
        cout<<ans+cnt<<"\n";
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;//cin>>T;
    while(T--)sol();
    return 0;
}
