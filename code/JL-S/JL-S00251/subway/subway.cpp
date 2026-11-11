#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans,dis=0x3f3f3f;
vector<int> g[500050];
vector<int> g1[500050];
vector<int> g2[500050];
int w[500050];
int a[1010][1010];
int t[1010][1010];
int k[500050];
void fun(int lt,int nw,int ed,int ln,int di)
{
    if(nw=ed)
    {
        dis=min(dis,di);
        return ;
    }
    for(int i=0;i<(int)g[a[ln][nw]].size();i++)
    {
        for(int j=0;j<(int)g2[g[a[ln][nw]][i]].size();j++)
        {
            if(a[i][j]!=a[ln][lt])
            {
                fun(nw,j,ed,i,di+t[ln][nw]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(i);
            g2[i].push_back(a[i][j]);
        }
        for(int j=1;j<=n;j++)
        {
            for(int l=j;l<=n;l++)
            {
                g1[a[i][j]].push_back(a[i][l]);
                g1[a[i][l]].push_back(a[i][j]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        bool f=false;
        int x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        for(int j=0;j<(int)g[x].size();j++)
        {
            for(int l=0;l<(int)g2[g[x][j]].size();l++)
            {
                if(g2[g[x][j]][l]==a[i][y])
                {
                    f=true;
                }
            }
            if(f) break;
        }
        if(f)
        {
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
