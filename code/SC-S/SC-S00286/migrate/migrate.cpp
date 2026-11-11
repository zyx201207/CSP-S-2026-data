#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll s[2000010];
vector<int> g[5010];
ll dis[5010];
ll ways[5010];

void bfs(ll st) {
	queue<ll> q;
	memset(dis,0x3f,sizeof(dis));
	q.push(st);
	dis[st]=0;
	ways[st]=0;
	while (q.size()) {
		int x=q.front();
		q.pop();
		for (ll to:g[x]) {
			if (dis[to]>dis[x]+1) {
				dis[to]=dis[x]+1;
				ways[to]=0;
				q.push(to);
			}
			if (dis[to]==dis[x]+1) {
				++ways[to];
			}
		}
	}
}

ll c,t;

void slv() {
	ll n,d;
	ll ans=0;
	cin>>n>>d;
	for (int i=1;i<=n;++i) {
		cin>>s[i];
	}
	if (c==11||c==12) {
		if (d<s[n]-s[n-1]) {
			cout<<0<<endl;
			return;
		}
	}
	for (int i=1;i<n;++i) {
		for (int j=i+1;j<=n;++j) {
			if (s[j]-s[i]<=d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	for (int i=1;i<=n;++i) {
		bfs(i);
		for (int j=i+1;j<=n;++j) {
			if (ways[j]==2) {
				++ans;
			}
		}
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) {
		g[i].clear();
	}
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while (t--) {
		slv();
	}
	return 0;
}
/*
wei2 yi1 da3 chu1 lai2 de0 bao4 li4 (TAT)
*/