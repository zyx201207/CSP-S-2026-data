#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, k[505], qq[300001], front = 1, rear = 0;
long long w[300001];
long long tmm[300001];
vector <int> a[505];
vector <long long> t[505]; 
vector <pair<int,int>> edges[300001];
vector <pair<int,int>> sedges[300001];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++){
		scanf("%d", &w[i]);
	}
	for (int i= 1; i <= n; i++){
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++){
			int aa;
			long long tt;
			scanf("%d%lld", aa, tt);
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
		for (int j = 1; j < k[i]; j++){
			edges[a[i][j]].push_back(make_pair(i, j + 1));
			sedges[a[i][j + 1]].push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 1; i < 300001; i++){
			tmm[i] = 1 << 60;
		}
		while (front <= rear){
			int p = qq[front++];
			for (auto pt : edges[p]){
				for (auto st : sedges[p]){
					tmm[a[pt.first][pt.second]] = min(tmm[a[pt.first][pt.second]], t[st.first][p] + t[pt.first][p]);
				}
			}
		}
		printf("%d\n", tmm[y]);
	}
	return 0;
}
