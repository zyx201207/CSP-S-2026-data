#include <bits/stdc++.h>//三维法骗近满分
using namespace std;//以线路为节点，地铁站为边，换乘时间为边长，构建图
long long dist[650][650], m, c, n, d, q, ans = 1e9; //dist用于记录不同线路换乘时间
int w[650], zhan, shi;

//int li[]
struct sub {
	int a[650], t[650]; //线路与时间
};
sub sta[100010];//车站？线路？仅仅是中间量，无关dist部分；车站！！sta:边;li:点

//priority_queue<int vector<int> greater<int> > a;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int z = 1; z <= m; z++) {
		cin >> w[z];
	}
	for (int z = 1; z <= n; z++) {
		int ki;
		cin >> ki;
		for (int y = 1; y <= ki; y++) {
			cin >> zhan >> shi;
			sta[zhan].a[z] = 1;
			sta[zhan].t[z] = shi;
		}
	}
	if (n == 1) {
		int sss, eee;
		for (int z = 1; z <= q; z++) {
			cin >> sss >> eee;
			/*	for(int y=;y<=;y++)
				{
					if(sta[sss].a [y]&&sta[eee].a [y])
					{
						ans=min(ans,dist[y][]);
					}
				}*/
			cout << w[sss] + w[eee] + sta[sss].t [1] + sta[eee].t [1] << endl;

		}
		return 0;
	}
	if (n == 2) {
		int sss, eee, aas;
		for (int i = 1; i <= q; i++) {
			cin >> sss >> eee;
			for (int z = 1; z <= m; z++) {
				if (sta[z].a [1] == sta[z].a [2]) {
					aas = min(aas, sta[z].t[1] + sta[z].t [2]);
				}
			}
			cout << w[sss] + w[eee] + sta[sss].t [1] + sta[eee].t [1]  << endl;
		}
		return 0;
	}

	for (int z = 1; z <= m; z++) {
		for (int y = 1; y <= m; y++) {
			for (int x = 1; x <= n; x++) {
				if (sta[z].a[x] && sta[y].a[x] ) {
					dist[z][y] = sta[z].t[x] + sta[y].t[x] ;
					dist[y][z] = sta[z].t[x] + sta[y].t[x] ;
				}
			}

		}
	}
	for (int k = 1; k <= n; k++) {
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				if (dist[x][y] > dist[x][k] + dist[k][y]) {
					dist[x][y] = dist[x][k] + dist[k][y];
					dist[y][x] = dist[x][k] + dist[k][y];
				}
			}
		}
	}
	/*	for (int z = 1; z <= n; z++) {
			for (int y = 1; y <= n; y++) {
				cout << dist[z][y] << ' ';
			}
			cout << endl;
		}*/
	int sss, eee;
	for (int z = 1; z <= q; z++) {
		cin >> sss >> eee;
		for (int i = 1; i <= n; i++) {
			for (int y = 1; y <= n; y++) {
				if (sta[sss].a [y] && sta[eee].a [i] && dist[y][i]) {
					ans = min(ans, dist[y][i]);
				}
			}
		}
		/*	for(int y=;y<=;y++)
			{
				if(sta[sss].a [y]&&sta[eee].a [i]&&dist[y][i])
				{
					ans=min(ans,dist[y][i]);
				}
			}*/
		//	cout << dist[sss][eee] + w[sss] + w[eee] << endl;
		cout << ans << endl;
		ans = 1e9;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/