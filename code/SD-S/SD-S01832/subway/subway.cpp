#include<bits/stdc++.h>
using namespace std;
struct road{
	int to, tim;
};
int c, n, m, d, q, w[500005], k, ina, inti, x, y, dis[500505], ans[501][500001];
vector <road>mp[500505];
void dij() {
	for(int i = 1; i <= n + m; i++)
		dis[i] = -1;
	dis[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int fro = q.front();
		q.pop();
		int size = mp[fro].size();
		for(int i = 0; i < size; i++) {
			if(dis[mp[fro][i].to] == -1 || dis[mp[fro][i].to] > dis[fro] + mp[fro][i].tim) {
				dis[mp[fro][i].to] = dis[fro] + mp[fro][i].tim;
				q.push(mp[fro][i].to);
			}
		}
	}
	
	for(int i = 1; i <= m; i++) 
		ans[x - m][i] = dis[i];
}
int main(){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> ina >> inti;
			road inz, inx;
			inz.to = i + m;inz.tim = inti;
			inx.to = ina;inx.tim = inti;
			mp[ina].push_back(inz);
			mp[m + i].push_back(inx);
		}
	}
	y = 1;
	for(x = m + 1; x <= m + n; x++) {
		dij();	
	}
	
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++)
//			cout << ans[i][j] << " ";
//		cout << endl;
//	}
	
	while(q--) {
		cin >> x >> y;
		int Ans = 2100000000;
		for(int i = 1; i < n; i++) {
			Ans = min(ans[i][y] + ans[i][x], Ans);
		}
		printf("%d\n", Ans + w[x] + w[y]);
	}
	
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
