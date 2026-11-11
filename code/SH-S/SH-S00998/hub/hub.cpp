#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000006;
int n,k,d[N];
vector<int> e[N];
int p[N][30];
vector<int> chose;
bool vst[N];
ll ans;
void dfs(int u,int fa)
{
    p[u][0]=fa;
    for(int k=1;k<=20;k++)
        p[u][k]=p[p[u][k-1]][k-1];
    d[u]=d[fa]+1;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if(d[u]>d[v])swap(u,v);
    for(int k=20;k>=0;k--)if(d[p[v][k]]>=d[u])v=p[v][k];
	if(u==v)return u;
    for(int k=20;k>=0;k--)if(p[u][k]!=p[v][k])u=p[u][k],v=p[v][k];
    return p[u][0];
}
ll dst(int u,int v)
{
    return d[u]+d[v]-2*d[lca(u,v)];
}
void chkdfs(int u)
{
    vst[u]=1;
    for(auto v:e[u])
    {
        if(vst[v])continue;
        if(*lower_bound(chose.begin(),chose.end(),v)!=v)continue;
        chkdfs(v);
    }
}
bool chk()
{
    memset(vst,0,sizeof(vst));
    int cnt=0;
    for(auto x:chose)
    {
        if(!vst[x])
        {
            cnt++;
            if(cnt==3)return false;
            chkdfs(x);
        }
    }
    return true;
}
ll cal()
{
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll tmp=1e18;
        for(auto x:chose)
        {
            tmp=min(tmp,dst(i,x));
        }
        res=max(res,tmp);
    }
    return res;
}
void bf(int t,int tag)
{
    if(t>k)
    {
        if(chk())
		{
			ans=min(ans,cal());
		}
        return;
    }
    for(int i=tag;i<=n;i++)
    {
        chose.push_back(i);
        bf(t+1,i+1);
        chose.pop_back();
    }
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int C,T;
	cin>>C>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)e[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1,0);
        ans=1e18;
        bf(1,1);
        cout<<ans<<endl;
    }
	return 0;
}

