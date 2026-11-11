#include<iostream>
using namespace std;
typedef long long LL;
const int N = 505, M = 5e5 + 5;
const LL INF = 9223372036854775807;
int c, n, m, d, q;
int w[M]; //这是每个站厅到地铁口的时间
int T[M][21][2]; //这是每个站台到站厅的时间
LL f[N][N]; //每条地铁到另一条的最短步行时间
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	// c为测试点编号, n为地铁数, m为地铁站数, d为最多站台地铁数, q为询问
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i == j) f[i][j] = 0;
			else f[i][j] = INF; //注意别直接加其他
	
	for(int i = 1; i <= m; i++)
		cin >> w[i];
	
	int sta1, sta2;
	for(int i = 1, k, tdata; i <= n; i++){ //输入每条地铁线路
		cin >> k;
		for(int j = 1; j <= k; j++){
			cin >> sta1 >> tdata;
			T[sta1][++T[sta1][0][0]][0] = i; //0存地铁
			T[sta1][T[sta1][0][0]][1] = tdata; //1存时间
		}
	}
	for(int k = 1; k <= m; k++){ //对每个地铁互相到达的时间进行更新
		for(int i = 1; i <= T[k][0][0]; i++){
			for(int j = 1; j <= T[k][0][0]; j++){
				f[T[k][j][0]][T[k][i][0]] = f[T[k][i][0]][T[k][j][0]] = min(f[T[k][i][0]][T[k][j][0]], T[k][i][1] + (LL)T[k][j][1]);
			}
		}
	}
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				if(f[i][k] == INF || f[k][j] == INF) //不能直接加
					continue;
				f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
			}
	
	LL ans;
	for(int k = 1; k <= q; k++){ //处理查询
		ans = INF;
		cin >> sta1 >> sta2;
		for(int i = 1; i <= T[sta1][0][0]; i++){
			for(int j = 1; j <= T[sta2][0][0]; j++){
				ans = min(ans, f[T[sta1][i][0]][T[sta2][j][0]] + T[sta1][i][1] + T[sta2][j][1]);
			}
		}
		cout << ans + w[sta1] + w[sta2] << '\n';
	}
}