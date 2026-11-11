#include<bits/stdc++.h>
using namespace std;
long long w[500010];
int a[550][500010];
long long t[550][500010];
vector<int> b[500010];
int ki[550];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> ki[i];
		for(int j = 1; j <= ki[i]; j++){
			cin >> a[i][j] >> t[i][j];
			b[a[i][j]].push_back(i);
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		long long ans = 0;
		int tmp = 0, re = 0;
		ans += w[x];
		for(int j = 0; j < b[x].size(); j++){
			for(int k = 0; k < b[y].size(); k++){
				if(j == k) tmp = 1, re = j;
			}
		}
		if(tmp){
			int r = 0;
			for(int j = 1; j <= ki[re]; j++){
				if(r) ans += t[re][j];
				if(a[re][j] == x) r = 1;
				if(a[re][j] == y) break;
			}
			ans += w[y];
		}
		cout << ans << endl;
	}
	return 0;
}