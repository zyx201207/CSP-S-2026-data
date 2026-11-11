#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 6e5 + 100 , mod = 1e9 + 7 , maxm = 550 , inf = 1e18;
const double eps = 1e-5;
inline int read() {
	int x = 0 , f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x) {
	if(x < 0) putchar('-') , x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void writeh(int x) {
	write(x);
	putchar('\n');
}
inline void writek(int x) {
	write(x);
	putchar(' ');
}
int c , n , m , d , q , w[maxn] , dis[maxm][maxm];
struct node {
	int id , w;
};
vector<node> vec[maxn];
inline void chkmin(int &x , int y) {
	x = x <= y ? x : y;
}
signed main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	c = read() , n = read() , m = read() , d = read() , q = read();
	memset(dis , 0x3f , sizeof dis);
	for(int i = 1; i <= m; ++i) w[i] = read();
	for(int i = 1; i <= n; ++i) {
		int k = read();
		dis[i][i] = 0;
		for(int j = 1 , x , y; j <= k; ++j) {
			x = read();
			y = read();
			vec[x].push_back({i , y});
		}
	}
	for(int i = 1; i <= m; ++i) {
		int k = vec[i].size();
		if(k == 1) continue;
		node u , v;
		for(int j = 0; j < k; ++j) {
			for(int o = j + 1; o < k; ++o) {
				u = vec[i][j];
				v = vec[i][o];
				chkmin(dis[v.id][u.id] , u.w + v.w);
				chkmin(dis[u.id][v.id] , u.w + v.w);
			}
		}
	}
	for(int o = 1; o <= n; ++o) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) chkmin(dis[i][j] , dis[i][o] + dis[o][j]);
	while(q--) {
		int x = read() , y = read();
		if(x == y) writeh(0);
		else {
			int ans = inf;
			for(auto u:vec[x]) for(auto v:vec[y]) chkmin(ans , dis[u.id][v.id] + u.w + v.w);
			writeh(ans + w[x] + w[y]);
		}
	}
	return 0;
}
/*
14:50 开始看题
感觉不是太会
有点神秘的题目
暴力是q*m*n*logn
优化一下
感觉这个d非常有说法
感觉会n*m*logn是，但感觉要炸掉
把最短路换成了floyd，现在是n^3+md的预处理
据说机子能跑1e9
不管了，直接撞过去
15：12打完

无限进步！
*/