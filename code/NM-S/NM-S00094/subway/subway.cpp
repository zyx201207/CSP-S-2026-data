#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
vector<int> w;
vector<int> k[550];
vector<int> k2[550];
int t[550][550];

int ans=INT_MAX;
int x,y;
int vis[550];
int visk[550];
void dfs(int r,int n,int x);
int main(void)
{
    freopen("subway.out","w",stdout);
    freopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    w.emplace_back(0);
    for(int i=0;i<m;i++)
    {
        int t=0;
        cin>>t;
        w.emplace_back(t);
    }
    for(int i=0;i<n;i++)
    {
        int ki=0;
        cin>>ki;
        for(int j=0;j<ki;j++)
        {
            int a=0;
            int b=0;
            cin>>a>>b;
            k[a].emplace_back(i);
            k2[i].emplace_back(a);
            t[a][j]=b;
        }

    }
    while(q--)
    {
        // memset(vis,550,0);

        cin>>x>>y;
        dfs(x,0,-1);
        vis[x]=1;
        cout<<ans<<endl;
        ans=INT_MAX;


    }
    return 0;
}
void dfs(int r,int n,int x)
{
    if(r==y)
    {
        ans=min(ans,n);
        return;
    }
    if(x==-1)
    {
        dfs(r,n+t[r][k[r][0]],k[r][0]);
    }
    for(int i=0;i<k2[x].size();i++)
    {
        if(!vis[k2[x][i]])
        {
            vis[k2[x][i]]=1;
            dfs(k2[x][i],n,x);
            vis[k2[x][i]]=0;
        }
    }
    for(int i=0;i<k[r].size();i++)
    {
        if(k[r][i]!=x)
        {
            dfs(r,n+w[r]+t[r][k[r][i]],k[r][i]);
        }
    }
}