#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,t,n,k;
vector<int> g[N];
int dep[N],fa[26][N],f[N];
bitset<N> choose;
void pre(int u,int f)
{
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    for (int i=1;i<=24;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int i=0;i<(int)g[u].size();i++)
    {
        int y=g[u][i];
        if (y==f) continue;
        pre(y,u);
    }
}
int lca(int a,int b)
{
    if (dep[a]<dep[b]) swap(a,b);
    for (int i=24;i>=0;i--) if (dep[fa[a][i]]<=dep[b]) a=fa[a][i];
    if (a==b) return a;
    for (int i=24;i>=0;i--) if (fa[a][i]!=fa[b][i]) a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
int dis(int a,int b)
{
    int l=lca(a,b);
    return dep[a]+dep[b]-2*dep[l];
}
int find(int x)
{
    if (x==f[x]) return x;
    else return f[x]=find(f[x]);
}
bool pd()
{
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<(int)g[i].size();j++)
        {
            int u=i,v=g[i][j];
            if (choose[u]==1 && choose[v]==1) {f[find(u)]=find(v);}
        }
    }
    int a=find(1),b=0;
    for (int i=1;i<=n;i++)
    {
        int t=find(i);
        if (choose[t]==0) continue;
        if (t==a) continue;
        if (b==0) {b=t;continue;}
        if (b==t) continue;
        if (a!=t && b!=t) return 0;
    }
    return 1;
}
int calc()
{
    long long ans=1e18;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (choose[j]==0) continue;
            ans=min(ans,1ll*dis(i,j));
        }
    }
    return ans;
}
long long res=1e18;
void bf(int d)
{

    if (d==k)
    {
        if (pd()==0) return;
        //cout<<calc()<<endl;
        res=min(res,1ll*calc());
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (choose[i]==1) continue;
        choose[i]=1;
        bf(d+1);
        choose[i]=0;
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
        for (int i=1;i<=n;i++) {g[i].clear();dep[i]=0;}
        for (int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        pre(1,0);
        choose.reset();
        res=1e18;
        bf(0);
        cout<<res<<"\n";
    }
    return 0;
}

//bf practice
/*
1.judge
if <2blocks?
2.calc 
min_max_min dis(i,j) 

judge o(n) by union set
clac O(n^2) 
pd O((n,k))

*/