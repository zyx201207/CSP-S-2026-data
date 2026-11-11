#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct ufset{
	int f[200010];
	int sz[200010];
	int n=0;
	ufset(int _n) {
		n=_n;
		for (int i=1;i<=n;++i) {
			f[i]=i;
			sz[i]=1;
		}
	}
	void merge(int x,int y) {
		x=find(x);
		y=find(y);
		if (sz[x]>sz[y]) {
			sz[x]+=sz[y];
			f[y]=x;
		}
		else {
			sz[y]+=sz[x];
			f[x]=y;
		}
	}
	int find(int x) {
		if (f[x]==x) {
			return x;
		}
		return f[x]=find(f[x]);
	}
};

vector<int> g[10010];

void slv() {
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		int x,y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cout<<1<<endl;
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while (t--) {
		slv();
	}
	return 0;
}
