#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 5e2 + 5, M = 5e5 + 5, mod = 998244353;
int c, n, m, d, q, w[M], dis[N][N];
vector< PII > v[M];

template< typename T > void read(T &x){x = 0;char ch = getchar();bool f = true;while (ch < '0' || ch > '9'){if (ch == '-') f = !f;ch = getchar();}while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch ^ 48);ch = getchar();}x = (f ? x : -x);}
template< typename T, typename ... L > void read(T &a, L && ... b){read(a);read(b ...);}
int ksm(int a, int b, int p){int ans = 1;while (b){if (b & 1) ans = ans * a % p;b >>= 1;a = a * a % p;}return ans;}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	read(c, n, m, d, q);
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1; i <= n; i++){
		int k, a, t;
		read(k);
		for (int j = 1; j <= k; j++){
			read(a, t);
			v[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; i++){
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++){
		for (int j = 0; j < v[i].size(); j++){
			for (int k = 0; k < j; k++){
				dis[v[i][j].first][v[i][k].first] = min(dis[v[i][j].first][v[i][k].first], v[i][j].second + v[i][k].second);
				dis[v[i][k].first][v[i][j].first] = min(dis[v[i][k].first][v[i][j].first], v[i][j].second + v[i][k].second);
			}
		}
	}
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	for (int i = 1; i <= q; i++){
		int x, y, dan = LONG_LONG_MAX;
		read(x, y);
		for (PII s : v[x]){
			for (PII t : v[y])
				dan = min(dan, s.second + t.second + dis[s.first][t.first]);
		}
		printf("%lld\n", dan + w[x] + w[y]);
	}
	return 0;
}
/*
在「茈」发动前的 41 秒内，新宿再次响起了五条悟的吟唱，「九纲」「偏光」「乌与声明」「表里之间」，宿傩知道，自己再也没有任何机会阻止「茈」的诞生了，无限制 
的虚式如同核爆一般在新宿上空亮起了冲天的光芒，魔虚罗的轮盘在「茈」中灰飞烟灭，废墟之中，拼尽全力抵挡的宿傩无力的倚靠在残破的建筑上支撑身体，他的半边手和 
腿都被这一击吞噬殆尽，同样伤痕累累的五条悟来到宿傩面前，宿傩立刻强迫自己不再依靠墙壁，堂堂正正地站在五条悟面前，但在术力同源的影响下五条悟受到的伤害大大 
削弱，在反转术士的治疗下，五条悟的身体再次恢复，对五条悟来说，决定性的一击远距离虚式「茈」只是其即兴创作的产物，谁能想到，魔虚罗和宿傩拼命阻止的，只是五 
条悟刚刚创作的一击，结果魔虚罗被秒，“看来完成的还算不错 ”，虎杖呆呆地望着屏幕不敢相信。“也就是说……”“没错，是五条悟赢了！”最强的战绩铭刻于新宿。

有错误请谅解 
感觉这场 T2，也没去年难啊 
*/
