#include <bits/stdc++.h>
using namespace std;
#define FIO(filename) freopen(filename".in","r",stdin);freopen(filename".out","w",stdout);
#define getchar() p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++
char buf[1000000], *p1 = buf, *p2 = buf;
template <typename T>
void read(T &x)
{
    x = 0;
    int f = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            f = -f;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + (c ^ '0');
    x *= f;
}
template <typename T, typename... Args>
void read(T &x, Args &...y)
{
    read(x);
    read(y...);
}
template <typename T>
void chkmx(T &x,T y){x=max(x,y);}
template <typename T>
void chkmn(T &x,T y){x=min(x,y);}
using ll = long long;
const int inf=1e9;
int cid;
void solve()
{
	if(cid==1||cid==2||cid==3)
	{
		int n,k;
    read(n,k);
    vector<vector<int>>a(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;read(u,v);
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    vector<int>fa(n+1);
    iota(fa.begin(),fa.end(),0);
    auto F=[&](int u)
    {
        while(u!=fa[u])
            u=fa[u]=fa[fa[u]];
        return fa[u];
    };
    auto U=[&](int u,int v){fa[F(u)]=F(v);};
    int ans=n;
    for(int S=0;S<1<<n;S++)
    {
        if(__builtin_popcount(S)!=k)
            continue;
        // if(S!=82)continue;
        iota(fa.begin(),fa.end(),0);
        for(int u=0;u<n;u++)
        {
            if(!(S>>u&1))continue;
            for(int v:a[u+1])
            {
                if(S>>(v-1)&1){
                    // cerr<<"link: "<<u+1<<' '<<v<<'\n';
                    U(u+1,v);
                }
            }
        }
        int cnt=0;
        for(int u=0;u<n;u++)
        {
            if(S>>u&1)
                cnt+=F(u+1)==u+1;
        }
        // cerr<<S<<' '<<cnt<<'\n';
        if(cnt>2)continue;
        queue<int>q;
        vector<int>dis(n+1,n+1);
        for(int u=0;u<n;u++)
        {
            if(S>>u&1)
                q.emplace(u+1),dis[u+1]=0;
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int v:a[u])
            {
                if(dis[v]>dis[u]+1)
                    q.emplace(v),dis[v]=dis[u]+1;
            }
        }
        int tmp=0;
        for(int u=1;u<=n;u++)chkmx(tmp,dis[u]);
        // if(tmp==1)
        // {
        // cout<<S<<' '<<tmp<<'\n';
        // for(int u=1;u<=n;u++)
        //     cout<<(S>>u-1&1)<<' '<<dis[u]<<'\n';
        // }
        chkmn(ans,tmp);
    }
    cout<<ans<<'\n';
    return;
	}
	int n,k;
	read(n,k);
	vector<vector<int>>a(n+1);
	for(int i=1;i<n;i++)
	{
		int u,v;read(u,v);
		a[u].emplace_back(v);
		a[v].emplace_back(u);
	}
	int X=n;
	vector<int>d(n+1);
	vector<int>need(n+1);
	vector<int>vis(n+1);
	vector<int>dep(n+1);
	int cnt=0;
	auto dfs=[&](auto self,int u,int p)->void
	{
		dep[u]=dep[p]+1;
		d[u]=inf;
		need[u]=X;
		for(int v:a[u])
		{
			if(v==p)continue;
			self(self,v,u);
			chkmn(d[u],d[v]+1);
			chkmn(need[u],need[v]-1);
		}
		// cerr<<u<<' '<<need[u]<<' '<<d[u]<<'\n';
		if(!need[u])
			vis[u]=1,d[u]=0,cnt++;
		if(d[u]<=need[u])
			need[u]=inf;
	};
	vector<int>fa(n+1);
	vector<int>sz(n+1);
	vector<int>tag(n+1);
	auto dfs2=[&](auto self,int u,int p)->bool
	{
		bool hv=vis[u];
		if(hv)
			tag[u]=1;
		for(int v:a[u])
		{
			if(v==p)continue;
			bool t=self(self,v,u);
			if(hv&&t)
				tag[u]=1;
			hv|=t;
		}
		return hv;
	};
	vector<int>deg(n+1);
	vector<int>f(n+1);
	vector<array<int,2>>son(n+1);
	auto dfs3=[&](auto self,int u,int p,int lstp)->void
	{
		sz[u]=vis[u];
		if(tag[u])fa[u]=lstp;
		deg[u]=lstp!=0;
		// if(tag[u])
		// 	f[u]=1;
		for(int v:a[u])
		{
			if(v==p)continue;
			self(self,v,u,tag[u]?u:lstp);
			sz[u]+=sz[v];
			deg[u]+=sz[v]>0;
			f[u]+=f[v];
		}
		if(f[u]>0||tag[u])
			f[u]++;
	};
	auto check=[&](int x)->bool
	{
		fill(vis.begin(),vis.end(),0);
		X=x;cnt=0;
		dfs(dfs,1,0);
		auto solve=[&]()->bool
		{
				if(cnt<=2)
					return 1;
				if(cnt>k)
					return 0;
				fill(fa.begin(),fa.end(),0);
				fill(sz.begin(),sz.end(),0);
				fill(tag.begin(),tag.end(),0);
				fill(deg.begin(),deg.end(),0);
				fill(f.begin(),f.end(),0);
				fill(son.begin(),son.end(),array<int,2>{0,0});
				dfs2(dfs2,1,0);
				dfs3(dfs3,1,0,0);
				// cout<<"fa: ";
				// for(int u=1;u<=n;u++)
				// 	cout<<fa[u]<<' ';
				// cout<<'\n';
				// cout<<"sz: ";
				// for(int u=1;u<=n;u++)
				// 	cout<<sz[u]<<' ';
				// cout<<'\n';
				// cout<<"tag: ";
				// for(int u=1;u<=n;u++)
				// 	cout<<tag[u]<<' ';
				// cout<<'\n';
				// cout<<"deg: ";
				// for(int u=1;u<=n;u++)
				// 	cout<<deg[u]<<' ';
				// cout<<'\n';
				for(int u=1;u<=n;u++)
				{
					if(tag[u])
					{
						(son[fa[u]][0]?son[fa[u]][1]:son[fa[u]][0])=u;
					}
				}
				int rt=-1;
				for(int u=1;u<=n;u++)
				{
					if(tag[u]&&!fa[u])
						rt=u;
				}
				// cerr<<rt<<' '<<f[rt]<<'\n';
				if(f[rt]<=k)
					return 1;
				for(int u=1;u<=n;u++)
				{
					if(!tag[u])continue;
					int ans=f[u];
					int p=fa[u];
					if(p)
					{
						int del=dep[u]-dep[p]-1;
						if(p==rt&&deg[p]<=2&&!vis[p])
						{
							int oth=son[p][0]==u?son[p][1]:son[p][0];
							ans=f[u]+f[oth];
						}
						else ans=f[rt]-del;
					}
					// cerr<<"del: "<<u<<' '<<ans<<'\n';
					if(ans<=k)
						return 1;
				}
				// cerr<<"failed"<<'\n';
				return 0;
		};
		int c=0;
		for(int u=1;u<=n;u++)
		{
			if(dep[u]-1==need[1]&&!vis[u])
			{
				c++;
			}
		}
		if(c<=10)
		{
			for(int u=1;u<=n;u++)
		{
			if(dep[u]-1==need[1]&&!vis[u])
			{
				// c++;
				vis[u]=1;
				cnt++;
				// break;
				// cerr<<u<<'\n';
				if(solve())return 1;
				vis[u]=0;
				cnt--;
				// need[1]=inf;
			}
		}
	}
		else if(n<=100)
		{
			for(int u=1;u<=n;u++)
		{
			if(dep[u]-1<=need[1]&&!vis[u])
			{
				// c++;
				vis[u]=1;
				cnt++;
				// break;
				// cerr<<u<<'\n';
				if(solve())return 1;
				vis[u]=0;
				cnt--;
				// need[1]=inf;
			}
		}for(int u=1;u<=n;u++)
		{
			if(dep[u]-1<=need[1]&&!vis[u])
			{
				// c++;
				vis[u]=1;
				cnt++;
				// break;
				// cerr<<u<<'\n';
				for(int v=u+1;v<=n;v++){
					if(vis[v])continue;
					vis[v]=1;
				cnt++;
				if(solve())return 1;
				vis[v]=0;
				cnt--;
			}
				vis[u]=0;
				cnt--;
				// need[1]=inf;
			}
		}
		}
		if(need[1]!=inf)
			vis[1]=1,cnt++;
		// cout<<"check: "<<x<<'\n';
		// for(int u=1;u<=n;u++)
		// 	cout<<vis[u]<<' ';
		// cout<<'\n';
		// cerr<<cnt<<'\n';
		if(solve())return 1;
		
		return 0;
	};
	int L=0,R=n,ans=n;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))R=(ans=mid)-1;
		else L=mid+1;
	}
	// check(1);
	cout<<ans<<'\n';
}
int main()
{
    FIO("hub");
	int t;
	read(cid,t);
	while(t--)solve();
    return 0;
}