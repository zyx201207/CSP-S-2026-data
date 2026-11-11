#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

int n,m,d;
long long mn=1e18;
int ed;
const int maxn=510,maxm=5e5+10;
int w[maxm],t[maxn][maxm];
int a[maxn][maxm];
bool vis[maxm];
vector<int> g[maxm];

void dfs(int u,long long tm,int ln)
{
    if(vis[u] || tm>mn) return;
    tm+=t[ln][u];
    if(u==ed)
    {
        mn=min(mn,tm);
        return;
    }
    vis[u]=1;
    for(int i:g[u])
    {
        int nt=tm+t[i][u];
        for(int j=1;j<=a[i][0];j++)
        {
            int v=a[i][j];
            if(v==u) continue;
            dfs(v,nt,i);
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i][0]);
        for(int j=1;j<=a[i][0];j++)
        {
            scanf("%d",&a[i][j]);
            scanf("%d",&t[i][a[i][j]]);
            g[a[i][j]].push_back(i);
        }
    }
    int x,y;
    while(q--)
    {
        scanf("%d%d",&x,&y);
        ed=y,mn=0x3f;
        memset(vis,0,sizeof(vis));
        dfs(x,w[x],0);
        mn+=w[y];
        cout << mn << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

