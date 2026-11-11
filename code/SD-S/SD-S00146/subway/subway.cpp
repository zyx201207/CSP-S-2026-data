#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=5e2+10,M=1e5+10;

using namespace std;

typedef pair<int,int> PII;

int w[N];
int k[N];
int a[N][M],t[N][M];

void solve() {
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		int last=0;
		for(int j=1; j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int sum=w[u]+w[v];
		cout<<sum<<endl;
	}
}

signed main() {

#ifdef Fre
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif

	int _=1;
	//cin>>_;
	while(_--) solve();

	return 0;
}//Oct31==Dec25?
