#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t;
int n,k;
int h[N],e[N],ne[N],idx;
int fa[N][11],dep[N];
int book[N];int q[N];
bool st[20];int res=0x3f3f3f3f;
void add(int a,int b)
{
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
void dfs1(int u)
{
    st[u]=true;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(st[j])continue;
        if(!book[j])continue;
        dfs1(j);
    }
}
bool check()
{
    memset(st,false,sizeof st);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!book[i])continue;
        if(st[i])continue;
        dfs1(i);cnt++;
    }
    return cnt<=2;
}
int lca(int a,int b)
{
    if(dep[a]<dep[b])swap(a,b);
    for(int k=10;k>=0;k--)
        if(dep[fa[a][k]]>=dep[b])
            a=fa[a][k];
    if(a==b)return a;
    for(int k=10;k>=0;k--)
        if(fa[a][k]!=fa[b][k])
            a=fa[a][k],b=fa[b][k];
    return fa[a][0];
}
int dis(int a,int b)
{
    return dep[a]+dep[b]-2*dep[lca(a,b)];
}
void solve(int u,int sum)
{
    if(sum>k)return;
    if(u==n+1)
    {
        if(sum!=k)return;
        //for(int i=1;i<=n;i++)
        //    cout<<book[i];
        //cout<<endl;
        if(!check())return;
        //for(int i=1;i<=n;i++)
         //   cout<<book[i];
        //cout<<endl;
        int now=0;
        for(int i=1;i<=n;i++)
        {
            int d=0x3f3f3f3f;
            for(int j=1;j<=n;j++)
            {
                if(!book[j])continue;
                d=min(d,dis(i,j));
            }
            now=max(now,d);
        }
        res=min(res,now);
        return;
    }
    book[u]=1;solve(u+1,sum+1);
    book[u]=0;solve(u+1,sum);
}
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    fa[u][0]=father;
    for(int k=1;k<=10;k++)
        fa[u][k]=fa[fa[u][k-1]][k-1];
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==father)continue;
        dfs(j,u);
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(h,-1,sizeof h);idx=0;
        res=0x3f3f3f3f;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);add(b,a);
        }
        dfs(1,0);
        solve(1,0);
        cout<<res<<endl;
        //break;
    }
    return 0;
}
