#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,m,f[N];
vector<vector<int> >v(N);
int mxp,fa[N],dep[N],mxdep[N];
int num1[N],num2[N];
priority_queue<pair<int,int> >p;
void DFS(int k)
{
    dep[k]=dep[fa[k]]+1;
    mxdep[k]=dep[k];
    for(int i=0; i<v[k].size(); i++)
    {
        if( v[k][i]!=fa[k] && f[v[k][i]]==0 )
        {
            fa[v[k][i]]=k;
            DFS(v[k][i]);
            mxdep[k]=max(mxdep[k],mxdep[v[k][i]]);
        }
    }
    if( dep[k]>dep[mxp] ) mxp=k;
}
int findmid(int k)
{
    mxp=0;
    DFS(k);
    int mx=mxp;
    fa[mx]=0;
    mxp=0;
    DFS(mx);
    int len=dep[mxp]-1;
    len/=2;
    while( len-- ) mxp=fa[mxp];
    mx=mxp;
    fa[mx]=0;
    DFS(mx);
    return mx;
}
int calc(int rt,int op)
{
    while( p.empty()==false ) p.pop();
    for(int i=0; i<v[rt].size(); i++)
        if( f[v[rt][i]]==0 )
            p.push({mxdep[v[rt][i]]-dep[rt],v[rt][i]});
    for(int i=1; i<=m; i++)
    {
        if( op==1 ) num1[i]=0;
        else        num2[i]=0;
    }
    for(int j=1; j<=m && p.empty()==false; j++)
    {
        if( op==1 ) num1[j]=p.top().first;
        else        num2[j]=p.top().first;
        int k=p.top().second; p.pop();
        for(int i=0; i<v[k].size(); i++)
            if( v[k][i]!=fa[k] && f[v[rt][i]]==0 )
                p.push({mxdep[v[k][i]]-dep[k],v[k][i]});
    }
    return p.top().first;
}
void solve()
{
    int mid=findmid(1);
    int ans=calc(mid,1);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            int x=i,y=v[i][j];
            fa[x]=0; f[y]=1;
            mid=findmid(x);
            calc(mid,1);
            f[y]=0;
            fa[x]=0; f[x]=1;
            mid=findmid(y);
            calc(mid,2);
            f[x]=0;
            for(int z=1; z<m; z++)
                ans=min(ans,max(num1[z],num2[m-z]));
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while( t-- )
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<n; i++)
        {
            int x,y; scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        solve();
        for(int i=1; i<=n; i++)
        {
            f[i]=fa[i]=dep[i]=mxdep[i]=0;
            v[i].resize(0);
        }
    }
    return 0;
}
