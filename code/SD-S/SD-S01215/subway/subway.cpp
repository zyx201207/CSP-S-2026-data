#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	
	int w[m+5]={0}, k[n+5]={0};
	vector<vector<int> > a(n+5);
	vector<vector<int> > t(n+5);
	vector<vector<int> > fa(n+5);
	int vis[n+5]={0};
	memset(vis+1, 0, n);
	int G[n+1][n+1];
	
	// input 
	for(int i=1;i<=m;i++) {
		cin >> w[i];
	}
	int cnt=0, tmp=-1;
	bool bFlag = true;
	for(int i=1;i<=n;i++) {
		cin >> k[i];
		a[i].push_back(-1);
		t[i].push_back(-1);
		for(int j=1;j<=2*k[i];j++) {
			int t1, t2;
			cin >> t1 >> t2;
			if (cnt==0) {
				tmp=t2;
			}
			a[i].push_back(t1);
			visited[t1]++;
			fa[t1].push_back(i);
			t[i].push_back(t2);
		}
	}
	
	int cost[n+1][n+1];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cost[i][j] = INT_MAX;
		}
	}
	
	for(int shit=0;shit<q;shit++) {
		int x, y;
		cin >> x >> y;
		bool flag1 = false;

		for (int i=0;i<fa[x].size();i++) {
			for (int j=0;j<fa[y].size();j++) {
				if(fa[x][i]==fa[y][j]) {
					flag1=true;
					break;
				}
			}
		}
		if(flag1) {
			cout << w[x] + w[y] << endl; 
		}
		if(n==2) {
			vector<int> huancheng;
			for(int i=1;i<=n;i++) {
				if(vis[i]>=2) huancheng.push_back(i);
			}
		}
		else {
			cout << w[x] + w[y] << endl; 
		}
	}

	
	return 0;
} 
