#include<bits/stdc++.h>

#define ll long long 
using namespace std;
#define sf cout << "\safe\n" << flush
const int maxn = 502;
const int maxm = 5e5+5;

struct node {
	int to, val;
};
vector<vector<ll>> flo;
int n, m, d, q;
int st[maxm],k[maxn];
vector<vector<pair<int,int>>> zhan;
vector<vector<ll>> a,t;
int F(int i,int j) {
	return i * (m+1) + a[i][j];
}
int iF(int v) {
	return v % (m+1);
}
int main () {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	flo.resize((n+2)*(m+3),vector<ll>((n+2)*(m+3),0x3f3f3f3f3f3f3f3f));
	zhan.resize(m+1);
	a.resize(n+1);
	t.resize(n+1);
	ll maxid = (n+1)*(m+2);
	for (int i = 1;i <= m ; i++ )  cin >> st[i];
	for (int i = 1; i <= n ; i++ )
	{
		cin >> k[i];
		a[i].resize(k[i]+1,0);
		t[i].resize(k[i]+1,0);
		for (int j=  1;j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			zhan[a[i][j]].push_back({i,j});
		}
	}
	for (int i =1;  i<= m; i++) {
		for (int j = 0; j<zhan[i].size();j++) {
			for (int l= 0;l<zhan[i].size();l++) {
				flo[zhan[i][j].first * (m+1) + i][zhan[i][l].first * (m+1) +i] =t[zhan[i][l].first][zhan[i][l].second];
			}
		}
		zhan[i].resize(0);
	}
	for ( int i= 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++ ) {
			for (int l = j; l <= k[i]; l++ ) {
				flo[F(i,j)][F(i,l)] = t[i][l];
			}
			flo[a[i][j]][F(i,j)] = st[a[i][j]] + t[i][j];
			flo[F(i,j)][a[i][j]] = st[a[i][j]];
		}
		a[i].resize(0);
		t[i].resize(0);
	}
	for (int i = 1; i <= maxid; i ++ ) flo[i][i] = 0;
	for (int k = 1; k <= maxid;k++) {
		for (int i = 1; i <= maxid;i++) {
			if (flo[i][k] == 0x3f3f3f3f3f3f3f3f) continue;
			for (int j = 1; j <=maxid;j++) {
				if (flo[k][j] == 0x3f3f3f3f3f3f3f3f) continue;
				flo[i][j] = min(flo[i][j],flo[i][k] + flo[k][j]);
			}
		}
	}
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << flo[u][v] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
