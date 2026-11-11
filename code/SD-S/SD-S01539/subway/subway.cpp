#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int c,n,m,d,q,k[500005],w[500005],dis[500005];
vector<int>a[505],t[505];
vector<pair<int,int> >G[500005];
queue<int>qq;
void dj(int x) {
	dis[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,x});
	while(pq.size()) {
		pair<int,int>top=pq.top();
		pq.pop();
		if(dis[top.second]!=top.first)continue;
		qq.push(top.second);
		for(pair<int,int>i:G[top.second]) {
			if(dis[top.second]+i.second<dis[i.first]) {
				dis[i.first]=dis[top.second]+i.second;
				pq.push({dis[i.first],i.first});
			}
		}
	}
}
void solve() {
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
		dis[i]=1e18;
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k[i]; j++) {
			for(int l=1; l<=k[i]; l++) {
				if(l==j)continue;
				G[a[i][j-1]].push_back({a[i][l-1],t[i][j-1]+t[i][l-1]});
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
		while(qq.size()) {
			dis[qq.front()]=1e18;
			qq.pop();
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

