#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int ww[100005];
struct node{
	int v,w;
	bool operator<(const node& other)const {
		return w>other.w;
	}
};
vector<node>ve[500505];

void solve() {
	int s,e;
	cin>>s>>e;
	bitset<500505>f;
	priority_queue<node>qu;
	qu.push({s,ww[s]});
	while(qu.size()) {
		node now=qu.top();
		qu.pop();
		if(now.v==e) {
			cout<<now.w+ww[e]<<'\n';
			return;
		}
		if(f[now.v]) continue;
		f[now.v]=1;
		for(int i=0;i<ve[now.v].size();i++) {
			node x=ve[now.v][i];
			qu.push({x.v,x.w+now.w});
		}
	}
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>ww[i];
	for(int i=1;i<=n;i++) {
		int x;
		cin >> x;
		while(x--) {
			int y,z;
			cin>>y>>z;
			ve[y].push_back({i+500000,z});
			ve[i+500000].push_back({y,z});
		}
	}
	while(q--) {
		solve();
	}
	return 0;
}
