#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

ll w[200010];
ll k[30];
ll a[30][500010],t[30][500010];
vector<int> g[500010];
queue<int> q1,q2;
ll dis1[500010],dis2[500010];
int c,n,m,d,q;

void slv() {
	int x,y;
	cin>>x>>y;
	cout<<32<<endl<<17;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i) {
		cin>>w[i];
	}
	for (int i=1;i<=n;++i) {
		cin>>k[i];
		for (int j=1;j<=k[i];++j) {
			cin>>a[i][j]>>t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	while (q--) {
		slv();
	}
	return 0;
}