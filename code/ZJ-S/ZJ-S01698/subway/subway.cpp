#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPS {
	using ll=long long;
	using pii=pair<int,int>;
	const int N=5e5+500+9; // max points
	const ll inf=0x3f3f3f3f3f3f3f3fll;
	int c,n,m,d,Q,W[N],qx[100009],qy[100009];
	struct edge {
		int v,w;
	};
	vector<edge>G[N];
	vector<pii>T[N];
	
	ll dis[N],ans[100009];
	struct node {
		int id;
		ll v;
		bool operator < (const node &other) const {
			return v>other.v;
		}
	};
	priority_queue<node>q;
	void dijkstra(int s) {
		memset(dis,0x3f,sizeof(dis));
		q.push({s,0});
		dis[s] = 0;
		while(q.size()) {
			node tt=q.top();q.pop();
			int u=tt.id;
			ll d=tt.v;
			if(dis[u]!=d) continue;
			for(edge tmp:G[u]) {
				int v=tmp.v;
				ll w=tmp.w;
				if(d+w<dis[v]) {
					dis[v] = d+w;
					q.push({v,dis[v]});
				}
			}
		}
	}
	
	int main() {
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cin>>c>>n>>m>>d>>Q;
		for(int i=1;i<=m;i++) cin>>W[i];
		for(int i=1;i<=n;i++) {
			int k,u=m+i;cin>>k;
			for(int j=1;j<=k;j++) {
				int v,w;cin>>v>>w;
				G[u].push_back({v,w});
				G[v].push_back({u,w});
			}
		}
		for(int i=1;i<=Q;i++) {
			cin>>qx[i]>>qy[i];
			T[qx[i]].push_back({qy[i],i});
		}
		memset(ans,0x3f,sizeof(ans));
		for(int i=m+1;i<=m+n;i++) {
			dijkstra(i);
			for(edge tmp:G[i]) {
				int j=tmp.v;
				ll w=tmp.w;
				for(pii tmp2:T[j]) {
					int y=tmp2.first,id=tmp2.second;
					ans[id] = min(ans[id],w+dis[y]);	
				}
			}
		}
		for(int i=1;i<=Q;i++)
			cout<<ans[i]+W[qx[i]]+W[qy[i]]<<"\n";
		return 0;
	}
}

int main() { return wsrCSPS::main(); }
/*
本题预计得分： 17*4=68 pts 
我现在写的这个是4e9复杂度，不知道在CCF机子上能不能骗更多分（？ 
*/
