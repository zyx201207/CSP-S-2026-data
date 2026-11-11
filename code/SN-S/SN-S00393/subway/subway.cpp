#include<bits/stdc++.h>
using namespace std;
int w[500005], t[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			int a;
			cin >> a;
			cin >> t[i][a];
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y, ans = 0;
		cin >> x >> y;
		ans += w[x] + w[y];
		for (int i = x; i <= y; i++){
			int k = 1, now = 100000;
			for (int k = 1; k < n; k++){
				if (t[k][i] == 0) k++;
				now = min(now, t[k][i]);
			}
			ans += now;	
		}
		cout << ans << "\n";
	}
	return 0;
}
//放弃了······
//地铁站布局可以看成是一个图，边长是两个站从站厅到站台的距离和（可能吧）。 
//但很明显我并不会图的知识。 
//也许应该尝试一下特殊性质？如果能做出来分差不多够了。 
//对B而言，就是说图的边长相等。那么只需找出最短路径即可。
//很明显这对我而言不可能。
//那只能凑了，但明显这串代码连样例都过不了······
