#include<bits/stdc++.h>
using namespace std;
int w[500005];
int k[500005];
int a[505][500005];
int t[505][500005];
int len[500005];
bool chk[500005];
vector <int> nodes[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q; 
	for (int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j ++){
			cin >> a[i][j] >> t[i][j];
			nodes[a[i][j]].push_back(i);
		}
	}
	while (q --){
		for (int i = 1;i <= m;i ++){
			len[i] = INT_MAX;
			chk[i] = 0;
		}
		int x, y;
		cin >> x >> y;
		len[x] = 0;
		int unchecked = m - 1;
		while (unchecked){
			int minn = INT_MAX;
			int now;
			for (int i = 1;i <= m;i ++){
				if (len[i] < minn){
					minn = len[i];
					now = i;
				}
			}
			chk[now] = 1;
			unchecked --;
			for (int i = 0;i < nodes[now].size();i ++){
				for (int j = 1;j <= k[nodes[now][i]];j ++){
					len[a[nodes[now][i]][j]] = len[now] + t[nodes[now][i]][now] + t[nodes[now][i]][a[nodes[now][i]][j]];
				}
			}
		}
		cout << len[y] + w[x] + w[y];
	}
	return 0;
}
