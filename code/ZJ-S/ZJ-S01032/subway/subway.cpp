#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 510 ,M = 5e5 + 10;
const ll INF = 2e18;
ll c ,n ,m ,d ,q;
ll w[M] ,ks[N];
vector<int> sta[M] ,dat[M]; //sta : stations relate to i and dat fot its length

ll ps[N][N] ,f[N][N]; //floyd part   ps : path


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.sync_with_stdio(false);
	cout.tie(0);
	freopen("subway.in" ,"r" ,stdin);
	freopen("subway.out" ,"w ",stdout);
	cin>>c>>n>>m>>d>>q;
	//sync_with_stdio(null);
	for (register int i=1 ;i<=m ;i++) {
		cin>>w[i];
	}
	for (register int i=1 ;i<=n ;i++) {
		cin>>ks[i];
		for (register int j=1 ;j<=ks[i] ;j++) {
			ll thia ,thit;
			cin>>thia>>thit;
			sta[thia].push_back(i);
			dat[thia].push_back(thit);
		}
	}
	
	//cout<<"SycamoreTy\n";
	// create graph
	for (register int i=1 ;i<=n ;i++) {
		for (register int j=1 ;j<=n ;j++) {
			f[i][j] = ps[i][j] = INF;
			if (i == j) {
				ps[i][j] = f[i][j] = 0;
			}
		}
	}
	for (register int i=1 ;i<=m ;i++) {
		for (register int j=0 ;j<sta[i].size() ;j++) {
			for (register int k=0 ;k<j ;k++) {
				ll u = sta[i][j] ,v = sta[i][k];
				ll thi = dat[i][j] + dat[i][k];
				ps[u][v] = ps[v][u] = min(ps[u][v] ,thi);
				f[u][v] = f[v][u] = ps[u][v];
			}
		}
	}
	// floyd
	for (register int k=1 ;k<=n ;k++) {
		for (register int i=1 ;i<=n ;i++) {
			for (register int j=1 ;j<i ;j++) {
				if (f[i][j] > f[i][k] + f[k][j]) {
					f[i][j] = f[j][i] = f[i][k] + f[k][j]; 
				}
			}
		}
	}
	
	for (register int i=1 ;i<=q ;i++) {
		ll u ,v ,ans = INF;
		cin>>u>>v;
		for (register int j=0 ;j<sta[u].size() ;j++) {
			for (register int k=0 ;k<sta[v].size() ;k++) {
				ll l = sta[u][j] ,r = sta[v][k];
				ll thi = dat[u][j] + dat[v][k] + f[l][r];
				ans = min(ans ,thi);
			}
		}
		cout<<ans + w[u] + w[v]<<"\n";
	}
	
	return 0;
}

//????30minkill 16:10
//jin tian wang guan le