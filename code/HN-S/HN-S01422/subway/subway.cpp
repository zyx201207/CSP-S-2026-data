#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[500005], f[505][505];
struct Line{
	int sum, stations[100005][2];
}lines[505];
struct Station{
	int sum, lines[505][2];
}stations[100005];
queue<int> qu;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	memset(f, 0x3f3f3f, sizeof(f));
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		lines[i].sum = k;
		f[i][i] = 0;
		for (int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			lines[i].stations[j][0] = a;
			lines[i].stations[j][1] = t;
			stations[a].lines[++stations[a].sum][0] = i;
			stations[a].lines[stations[a].sum][1] = t;
		}
	}
	for (int k = 1; k <= n; k++){
		qu.push(k);
		while (!qu.empty()){
			int now = qu.front();
			for (int i = 1; i <= lines[now].sum; i++){
				for (int j = 1; j <= stations[lines[now].stations[i][0]].sum; j++){
					if (stations[lines[now].stations[i][0]].lines[j][0] != now){
						if (f[k][stations[lines[now].stations[i][0]].lines[j][0]] > lines[now].stations[i][1] + stations[lines[now].stations[i][0]].lines[j][1] + f[k][now]){
							f[k][stations[lines[now].stations[i][0]].lines[j][0]] = lines[now].stations[i][1] + stations[lines[now].stations[i][0]].lines[j][1] + f[k][now];
							qu.push(stations[lines[now].stations[i][0]].lines[j][0]);
						}
					}
				}
			}
			qu.pop();
		}
	}
	for (int i = 1; i <= q; i++){
		long long x, y, ans = 9999999999;
		cin >> x >> y;
		for (int i = 1; i <= stations[x].sum; i++){
			for (int j = 1; j <= stations[y].sum; j++){
				ans = min(ans, f[stations[x].lines[i][0]][stations[y].lines[j][0]]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//line -> point
//line -- line -> w = min
