#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<int> w(m+1);
	vector<vector<int> > a(n+1,vector<int> (m+1));
	vector<vector<int> > t(n+1,vector<int> (m+1));
	vector<int> k(n+1);
	vector<vector<int> > plan(q,vector<int>(2));
	for(int i = 1 ; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1 ; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i] ; j ++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q ; i ++) {
		cin >> plan[i][1] >> plan[i][2];
	}

	if(c>=7 && c <= 11) {
		int ans = 0;
		for(int pl = 1 ; pl <= q ; pl++) {
			vector<vector<int> > g(m,vector<int>(m));
			vector<vector<int> > gr(m);
			int start = plan[pl][1];
			int end = plan[pl][2];
			for(int i = 1 ; i <= n ; i ++) {
				g[a[i][1]][a[i][2]] = t[i][1] + t[i][2];
				gr[a[i][1]].push_back(a[i][2]);
			}
			queue<int> q;
			q.push(start);
			while(!q.empty()) {
				int u = q.front();
				if(u == end) {
					cout << ans << endl;
					break;
				}
				q.pop();
				for(int i = 1 ; i <= gr[i].size() ; i ++) {
					q.push(gr[u][i]);
				}
				ans += g[u][q.front()];
			}
		}
	}


//what a shit i made
	return 0;
}
