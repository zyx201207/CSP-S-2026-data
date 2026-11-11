#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=505, M=1005;

int n, m;
ll w[N];
int a[N][M];
ll t[N][M];
vector<vector<ll>> dist(M, vector<ll>(M, INF));

void Floyd() {
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=1; k<=m; k++) {
				if(dist[i][k]==INF || dist[k][j]==INF) continue;
				dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c, d, q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int k;
	for(int i=1; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			cin>>a[i][j]>>t[i][j];
			for(int l=1; l<j; l++) { 
				int u=a[i][j], v=a[i][l];
				dist[u][v]=(t[i][j]+t[i][l]);
				dist[v][u]=(t[i][l]+t[i][j]);
			}
		}
	}
	Floyd();

	while(q--) {
		int x, y;
		cin>>x>>y;
		ll ans=dist[x][y]+w[x]+w[y];
		cout<<ans<<endl;
	}
	cout<<endl;
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=m; j++) {
			cout<<dist[i][j]<<" ";
		} cout<<endl;
	}
	
	return 0;
}

