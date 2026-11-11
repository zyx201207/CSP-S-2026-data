#include<bits/stdc++.h>
using namespace std;
/*

*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
const int N=110,inf=1e9+10000;
int Case,T,n,k,i,j,x,y,ans;
bool in[N],vis[N];
int last[N],c;
int d[N][N];
struct Node{
    int to,nxt;
}a[N<<1];
void add(int u,int v)
{
    a[++c]={v,last[u]};
    last[u]=c;
}
void DFS(int x)
{
    int i,to;
    vis[x]=true;
    for (i=last[x];i;i=a[i].nxt)
    {
        to=a[i].to;
        if (!vis[to]&&in[to]) DFS(to); 
    }
}
void dfs(int x,int fa,int root)
{
    int i,to;
    for (i=last[x];i;i=a[i].nxt)
    {
        to=a[i].to;
        if (to==fa) continue;
        d[root][to]=d[root][x]+1;
        dfs(to,x,root);
    }
}
void calc()
{
    int i,j,cnt=0,dis,res=0;
    for (i=1;i<=n;i++) vis[i]=false;
    for (i=1;i<=n;i++)
    {
        if (in[i]&&!vis[i])
        {
            cnt++;
            DFS(i);
        }
    }
    if (cnt>2) return;
    for (i=1;i<=n;i++)
    {
        d[i][i]=0;
        dfs(i,0,i);
    }
    for (i=1;i<=n;i++)
    {
        dis=inf;
        for (j=1;j<=n;j++)
        {
            if (in[j]) dis=min(dis,d[i][j]);
        }
        res=max(res,dis);
    }
    ans=min(ans,res);
}
void fun(int dep,int cnt)
{
    if (dep>n)
    {
        if (cnt==k) calc();
        return;
    }
    in[dep]=true;
    fun(dep+1,cnt+1);
    in[dep]=false;
    fun(dep+1,cnt);
}
void work()
{
    scan>>n>>k;
    for (i=1;i<=n;i++) last[i]=0;
    c=0;
    for (i=1;i<n;i++)
    {
        scan>>x>>y;
        add(x,y);
        add(y,x);
    }
    ans=inf;
    fun(1,0);
    printf("%d\n",ans);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scan>>Case>>T;
    while (T--) work();
    return 0;
}