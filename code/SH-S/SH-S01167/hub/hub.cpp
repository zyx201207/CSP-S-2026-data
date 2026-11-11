#include <bits/stdc++.h>
using namespace std;

#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back

const int inf=1e18;
int cid,T;
namespace solvebf{
	const int maxn=4e3+10;
	int n=0,k,dis[maxn][maxn],res=0,f[maxn],g[maxn],mxd[maxn],h[maxn],s[maxn],_s[maxn],tmp;
	//f_x:is x chosen?
	//g_x:mx_dep 
	bitset<maxn> tag,vis;
	vector<int> e[maxn];
	queue<int> q;
	void bfs(int x){
		memset(dis[x],0x3f,sizeof(dis[x]));
		q.push(x);
		dis[x][x]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				if(dis[x][u]+1<dis[x][v]){
					dis[x][v]=dis[x][u]+1;
					q.push(v);
				}
			}
		}
	}
//	bool ffllaagg=0;
	void dfs(int x,int fa){
		vis[x]=1;
		f[x]=0,g[x]=0,mxd[x]=1;
		for(auto u:e[x]) if((u^fa)&&tag[u]){
//			if(ffllaagg) cout<<x<<" -> "<<u<<"\n";
			dfs(u,x);
			mxd[x]=max(mxd[x],mxd[u]+1);
			if(f[u]) f[x]=1;
			g[x]=max(g[x],g[u]+1);
			_s[x]+=_s[u];
		}
		if(g[x]>=tmp) f[x]=1;
		_s[x]+=f[x];
	}
	void dfs1(int x,int fa){
		int mx1=h[x]+1,mx2=-inf,pos1=-1,pos2=-1;
		for(auto u:e[x]) if((u^fa)&&vis[u]){
			if(mxd[u]>mx1){
				pos2=pos1;
				mx2=mx1;
				pos1=u;
				mx1=mxd[u];
			}
			else if(mxd[u]>mx2){
				mx2=mxd[u];
				pos2=u;
			}
		}
		for(auto u:e[x]) if((u^fa)&&tag[u]){
			if(u==pos1) h[u]=mx2;
			else h[u]=mx1;
			dfs1(u,x);
		}
	}
	void dfs2(int x,int fa,int rt){
		bool flag=0;
		if(dis[x][rt]>tmp) flag=1;
		for(auto u:e[x]) if((u^fa)&&(u^rt)){
			dfs2(u,x,rt);
			if(tag[u]) flag=1;
		}
		tag[x]=flag;
	}
	bool check(int x){
		tmp=x;
		memset(f,0,sizeof(f));
		memset(_s,0,sizeof(_s));
		tag.set();
//		ffllaagg=1;
//		cout<<"dfs"<<"\n";
		dfs(1,-1);
		for(int i=1;i<=n;i++) if(!_s[i]) _s[i]++;
		for(int i=1;i<=n;i++) s[i]=_s[i];
//		cerr<<"now:"<<x<<"\n";
		if(s[1]<=k) return 1;
		for(int i=2;i<=n;i++){
			tag.set();
			memset(_s,0,sizeof(_s));
			memset(f,0,sizeof(f));
			dfs2(1,-1,i);
			tag[i]=0;
			vis.reset();
			dfs(1,-1);
			h[1]=0;
			dfs1(1,-1);
			for(int j=1;j<=n;j++) if(!_s[j]) _s[j]++;
			if(s[i]+_s[1]<=k) return 1;
			for(int j=2;j<=n;j++) if(vis[j]){
				
				if(h[j]<=x&&s[i]+_s[j]<=k){
//					cerr<<"out:"<<i<<" "<<j<<" "<<h[j]<<" "<<s[i]<<" "<<_s[j]<<"\n";
					return 1;
				}
			}
		}
		return 0;
	}
	void solve(){
		for(int i=1;i<=n;i++) e[i].clear();
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		if(n<=k){
			cout<<0<<"\n";
			return;
		}
		for(int i=1;i<=n;i++) bfs(i);
		int l=1,r=n,mid=(l+r)>>1;
		while(r>l){
			if(check(mid)) r=mid;
			else l=mid+1;
			mid=(l+r)>>1;
		}
		cout<<mid<<"\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>cid>>T;
	while(T--){
		if(cid<=10) solvebf::solve();
		else cout<<"114514\n";
	}
	return 0;
}

/*
first divided and turn this prob into check if x is ok

let's think if we know a cb's lca,and we can take away the subtree.
let's think if we take away a subtree from the T and we only allow one cb,how can we solve the problem?

OK,O(n^2 log n)'s solution is native.
*/
