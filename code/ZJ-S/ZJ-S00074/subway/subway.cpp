#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D=25,N=5e2+5,M=5e5+5;
const ll inf=1e18;
struct node {
	ll xi,ti;
};
ll c,n,m,d,q,w[M],k[N];
vector<node> x[M];
ll ans,dis1[N][N],dis2[N][N];
bool vis[N];
//,g[N][N];
vector<int> g[N];


struct edge {
	ll v,w;
	bool operator<(const edge A)const {
		return w>A.w;
	}
};
inline void dijskra(int s) {
	priority_queue<edge> q;
	q.push({s,0});
	for(int i=0; i<=n; i++) {
		dis2[s][i]=inf;
		vis[i]=false;
	}
	dis2[s][s]=0;
//	int cnt=0;
	for(; !q.empty();) {
		ll u=q.top().v,d=q.top().w;
		q.pop();
		if(!vis[u]) {
			vis[u]=true;
			if(d<=dis2[s][u]) {
				for(auto it:g[u]) {
					if(dis2[s][it]>d+dis1[u][it]) {
						dis2[s][it]=d+dis1[u][it];
						q.push({it,dis2[s][it]});
					}
					//cnt++;

				}
			}
		}
	}
	//cerr<<cnt<<"\n";
	return;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			dis1[i][j]=inf;
			if(i==j) {

				dis1[i][j]=0;
			}
		}
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1,aa,tt; j<=k[i]; j++) {
			cin>>aa>>tt;
			x[aa].push_back({i,tt});
		}
	}
	/*
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k[i]; j++) {
			mp[i][a[i][j]]++;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			for(auto it:mp[j]){
				if(mp[i].count(it)){

				}
			}
		}
	}
	*/

	for(int i=1; i<=m; i++) {
		for(auto j:x[i]) {
			for(auto k:x[i]) {
				dis1[j.xi][k.xi]=min(dis1[j.xi][k.xi],j.ti+k.ti);
				dis1[k.xi][j.xi]=min(dis1[k.xi][j.xi],j.ti+k.ti);
				g[k.xi].push_back(j.xi);
				g[j.xi].push_back(k.xi);
			}
		}
	}





	if(c>=9 && c<=15) {


		for(int i=1; i<=n; i++) {
			sort(g[i].begin(),g[i].end());
			unique(g[i].begin(),g[i].end());
		}
		for(int i=1; i<=n; i++) {
			dijskra(i);
		}
	} else {

		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				if(k!=i) {
					for(int j=1; j<=n; j++) {
						dis1[i][j]=min(dis1[i][j],dis1[i][k]+dis1[k][j]);
					}
				}
			}
		}
	}


	for(int _=1,xx,yy; _<=q; _++) {
		ans=0;
		cin>>xx>>yy;
		ans+=w[xx],ans+=w[yy];
		ll res=inf;

		if(c>=9 && c<=15) {

			for(auto j:x[xx]) {
				for(auto k:x[yy]) {
					res=min(res,dis2[j.xi][k.xi]+j.ti+k.ti);
				}
			}
		} else {


			for(auto j:x[xx]) {
				for(auto k:x[yy]) {
					res=min(res,dis1[j.xi][k.xi]+j.ti+k.ti);
				}
			}

		}
		ans+=res;
		cout<<ans<<"\n";
	}
	return 0;
}