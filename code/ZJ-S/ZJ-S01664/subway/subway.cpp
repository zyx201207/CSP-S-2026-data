#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

inline int read();
void write(int);
void writeln(int);

const int M = 1e3 + 5;
int c, n, m, d, q, w[M], dis[M << 1][M << 1];

signed main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++) {
		int k = read();
		while(k--) {
			int a = read(), t = read();
			dis[a][m + i] = dis[m + i][a] = t;			
		}
	}
	for(int i = 1; i <= m + n; i++) dis[i][i] = 0;
	for(int k = 1; k <= m + n; k++)
		for(int i = 1; i <= m + n; i++)
			for(int j = 1; j <= m + n; j++)
				if(i != j && j != k && k != i)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); 
	while(q--) {
		int x = read(), y = read();
		printf("%d\n", w[x] + w[y] + dis[x][y]);
	}
	
	return 0;

}

inline int read() {
	int res = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	static int sta[35]; int top = 0;
	do { sta[++top] = x % 10, x /= 10; } while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}

