#include <bits/stdc++.h>
using namespace std;
bool f[5001];
struct o{
	int now, w;
	o(int _now, int _w){
		now = _now;
		w = _w;
	}
};
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, tot[5001], k, a[5001][5001], t[5001][5001], x, y;
	vector <int> su[5001];
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> tot[i];
	}
	if(c >= 7 && c <= 11){
		cin >> k;
		for(int j = 1; j <= n; j++) {
			for(int i = 1; i <= k; i++) {
				cin >> a[j][i] >> t[j][i];
				
			}
			if(k == 2){
				su[a[j][1]].push_back(a[j][2]);
				su[a[j][2]].push_back(a[j][1]);
			}
		}
		cin >> x >> y;
		queue <o> q;
		q.push(o(x, 0));
		while(!q.empty()){
			o now = q.front();
			q.pop();
			if(now.now == y){
				cout << now.w;
				break;
			}
			for(int i = 0; i < su[now.now].size(); i++){
				if(!f[su[now.now][i]]){
					q.push(o(su[now.now][i], now.w + 2 * t[now.now][now.now]));
					f[su[now.now][i]] = 1;
				}
			}
		}
	}
	return 0;
}