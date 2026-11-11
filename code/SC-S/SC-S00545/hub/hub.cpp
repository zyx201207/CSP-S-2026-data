#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+3;
int c,t,n,k,sz[N],dep[N],maxd[N],dfn[N],dfncnt;
vector<int>g[N];
void dfs(int u,int fa){
	dfn[u]=++dfncnt;
	sz[u]=1;
	for(int v:g[u]){
		if(v==fa)	continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	return ;
}
bool need[N];
void dfs2(int u,int fa,int x){
	maxd[u]=dep[u];
	for(int v:g[u]){
		if(v==fa)	continue;
		dfs2(v,u,x);
		maxd[u]=max(maxd[u],maxd[v]);
	}
	if(maxd[u]-dep[u]==x)	need[u]=1,maxd[u]=0/*,cout<<"need"<<u<<'\n'*/;
	return ;
}
int res,scc;
void solve(int u,int fa,int cnt){
	if(res)	return ;
//	cout<<u<<' '<<fa<<' '<<scc<<' '<<cnt<<'\n';
	if(need[u]){
		if(!need[fa])	scc++;
		if(scc>2)	return ;
		for(int v:g[u]){
			if(v==fa)	continue;
			solve(v,u,cnt+1);
		}
	}
	if(dfn[u]==n){
		if(scc<=2&&cnt<=k)	res=1;
		return ;
	}
	if(!need[u]){
		for(int v:g[u]){
			if(v==fa)	continue;
			solve(v,u,cnt);
		}
		need[u]=1;
		if(!need[fa])	scc++;
		if(scc<=2){
			for(int v:g[u]){
				if(v==fa)	continue;
				solve(v,u,cnt+1);
			}
		}
		if(!need[fa])	scc--;
		need[u]=0;
	}
	return ;
}
bool check(int x){
//	cout<<"x:"<<x<<'\n';
	for(int i=1;i<=n;i++)	need[i]=0;
	dfs2(1,0,x);
	res=scc=0;
	solve(1,0,0);
	return res;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)	g[i]=vector<int>();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfncnt=0;
		dfs(1,0);
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))	r=mid;
			else	l=mid+1;
		}
		cout<<r<<'\n';
	}
	return 0;
}/*
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+3;
int c,t,n,k,sz[N],dep[N],maxd[N],dfn[N],dfncnt;
vector<int>g[N];
void dfs(int u,int fa){
	dfn[u]=++dfncnt;
	sz[u]=1;
	for(int v:g[u]){
		if(v==fa)	continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	return ;
}
bool need[N];
void dfs2(int u,int fa,int x){
	maxd[u]=dep[u];
	for(int v:g[u]){
		if(v==fa)	continue;
		dfs2(v,u,x);
		maxd[u]=max(maxd[u],maxd[v]);
	}
	if(maxd[u]-dep[u]==x)	need[u]=1,maxd[u]=0,cout<<"need"<<u<<'\n';
	return ;
}
int scc(int u,int fa){
	int res=0;
	if(need[u]&&!need[fa])	res++;
	for(int v:g[u]){
		if(v==fa)	continue;
		res+=scc(v,u);
	}
	return res;
}
int res;
void solve(int u,int fa,int cnt){
	if(res)	return ;
//	cout<<u<<' '<<fa<<' '<<cnt<<' '<<scc(1,0)<<'\n';
	if(need[u]){
		for(int v:g[u]){
			if(v==fa)	continue;
			solve(v,u,cnt+1);
		}
	}
	if(dfn[u]==n){
//		for(int i=1;i<=n;i++)	cout<<need[i]<<' ';
//		cout<<'\n';
//		cout<<"scc:"<<scc<<' '<<cnt<<'\n';
		if(cnt<=k&&scc(1,0)<=2)	res=1;
		return ;
	}
	if(!need[u]){
		for(int v:g[u]){
			if(v==fa)	continue;
			solve(v,u,cnt);
		}
		need[u]=1;
		for(int v:g[u]){
			if(v==fa)	continue;
			solve(v,u,cnt+1);
		}
		need[u]=0;
	}
	return ;
}
bool check(int x){
	cout<<"x:"<<x<<'\n';
	for(int i=1;i<=n;i++)	need[i]=0;
	dfs2(1,0,x);
	res=0;
	solve(1,0,0);
	return res;
}
int main(){
	freopen("hub1.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)	g[i]=vector<int>();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfncnt=0;
		dfs(1,0);
		int l=1,r=n;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid))	r=mid;
			else	l=mid+1;
		}
		cout<<r<<'\n';
	}
	return 0;
}
*/