#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define pb push_back
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

using namespace std;

const int N = 1e6+500+10;
int c,n,m,d,Q,id=0;
vector<pair<ll,int>> g[N];
vector<ll> ds;
vector<bool> vs;

priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int> > > pq;
void Dijistra(int st) {
	for(int i=1;i<=id;i++) ds[i]=llinf,vs[i]=0;
	ds[st]=0;pq.push({0,st});
	while(!pq.empty()) {
		int nw=pq.top().second;
		ll w=pq.top().first;
		pq.pop();
		if(vs[nw]) continue;
		vs[nw]=1;ds[nw]=w;
		for(auto i:g[nw]) {
			int nt=i.second;
			ll w_=i.first;
			if(ds[nt]>ds[nw]+w_) {
				ds[nt]=ds[nw]+w_;
				pq.push({ds[nt],nt}); 
			}
		}
	}
}

int main() {
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
	CLOSE
	cin>>c>>n>>m>>d>>Q;
	for(int w,i=1;i<=m;i++) {
		++id;
		cin>>w;
		g[id].pb({w,id+m}); 
		g[id+m].pb({w,id});
	}
	id=m*2;
	for(int k,i=1;i<=n;i++) {
		++id;
		cin>>k;
		for(int t,a,j=1;j<=k;j++) {
			cin>>a>>t;
			g[id].pb({t,a});
			g[a].pb({t,id});
		}
	}
	ds.resize(id+5);vs.resize(id+5);
	while(Q--) {
		int st,ed;
		cin>>st>>ed;
		Dijistra(st+m);
		cout<<ds[ed+m]<<'\n';
	}

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

fc subway.out subway3.ans

*/

