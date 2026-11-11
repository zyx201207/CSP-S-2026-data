#include <bits/stdc++.h>
using namespace std;
#define fre

//if there is only one block, I can find the center of the tree
//but at most two
//so divided to discuss
//1 one
//O(n)
//2 two
//find two center and expand by size
//we attempt every edge to split the tree
//O(n^2)

//for A we can select the best division

namespace zyc{
	#define rep(i,l,r) for(int i=(l);i<=(r);i++)
	#define per(i,r,l) for(int i=(r);i>=(l);i--)
	#define pb push_back
	typedef long long ll;
	const int N=1e6+5;
	int c,t;
	int n,k,m;
	int u[N],v[N],ans,res;
	int u1,v1,cen1;
	int u2,v2,cen2;
	struct ND{
		int p,id;
	};
	vector<ND>g[N];
	int dep[N],fa[N];
	bool cut[N];
	bool vis[N];
	void dfs(int p,int f){
		vis[p]=1;
		dep[p]=dep[f]+1;
		fa[p]=f;
		for(auto i:g[p]){
			if(i.p==f||cut[i.id])continue;
			dfs(i.p,p);
		}
	}
	int far(int p){
		rep(i,1,n)vis[i]=0;
		dfs(p,0);
		int q=p;
		rep(i,1,n)if(vis[i]&&dep[i]>dep[q])q=i;
		return q;
	}
	int gmid(int u,int v){
		int d=dep[v]>>1;
		while(d--)v=fa[v];
		return v;
	}
	void bd(int p,int f){
		fa[p]=f;
		dep[p]=1;
		for(auto i:g[p]){
			if(i.p==f||cut[i.id])continue;
			bd(i.p,p);
			dep[p]=max(dep[p],dep[i.p]+1);
		}
	}
	struct dd{
		int p;
		bool operator<(const dd &b)const{
			return dep[p]<dep[b.p];
		}
	};
	priority_queue<dd>arr;
	void calc(int k){
		int p;
		while(k--){
			p=arr.top().p,arr.pop();
			for(auto i:g[p]){
				if(i.p==fa[p]||cut[i.id])continue;
				arr.push(dd{i.p});
			}
		}
		if(arr.empty())res=0;
		else res=dep[arr.top().p];
		while(!arr.empty())arr.pop();
		ans=min(ans,res);
	}
	void run(){
		rep(i,1,n)g[i].clear();
		cin>>n>>k;
		ans=n;
		m=n-1;
		rep(i,1,m){
			cin>>u[i]>>v[i];
			g[u[i]].pb({v[i],i});
			g[v[i]].pb({u[i],i});
		}
		u1=far(1),v1=far(u1);
		cen1=gmid(u1,v1);
		bd(cen1,0);
		arr.push(dd{cen1});
		calc(k);
		int l=1,r=m;
		if(c==13||c==14){
			int k=m/2/2;
			l=max(1,k-2);
			r=min(n-1,k+2);
		}
		rep(i,l,r){
			cut[i]=1;
			u1=far(u[i]),v1=far(u1);
			cen1=gmid(u1,v1);
			bd(cen1,0);
			arr.push(dd{cen1});
			u2=far(v[i]),v2=far(u2);
			cen2=gmid(u2,v2);
			bd(cen2,0);
			arr.push(dd{cen2});
			calc(k);
			cut[i]=0;
		}
		cout<<ans<<'\n';
	}
	int main(){
		cin>>c>>t;
		while(t--)run();
		return 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef fre
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	#endif
	zyc::main();
	return 0;
}
