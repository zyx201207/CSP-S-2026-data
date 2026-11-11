#include<bits/stdc++.h>

#define MAXN 500005
#define MAXA 666

using namespace std;

int c, n, m, d, q;
int w[MAXN], sub[MAXA][MAXA];
int dx, dy;//dot 

// 第Q条线路X至Y距离 
int totalwalk(int q, int x, int y) {
	int total;
	if(x > y) {
		swap(x, y);
	}
	for(int i = x; i <= y; i++) {
		total += sub[q][i];
	}
	return total;
}

//第x条线路中是否含有Y 
bool have(int x, int y) {
	for(int i = 1; i <= 2 * sub[x][0]; i++) {
		if(sub[x][i] == y) return 1;
	}
	return 0;
}

//判断X交Y是否为空 ,并返回时间 
int same(int x, int y) {
	for(int i = 1; i <= 2 * sub[x][0]; i++) {
			for(int j = 1; j <= 2 * sub[y][0]; j++) {
				if(sub[x][i] == sub[y][i]) {
				//此时I为换乘站
				int add = totalwalk(x, dx, i);
				int plus = totalwalk(y, dy, i);
				return add + plus;
			}
		}
	}
	return 0;
}

//出行方案是否可行 
bool solution(int a, int b) {
	if(have(a, dx) && have(b, dy) && same(a, b)) return 1;
	else return 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(sub, -1, sizeof(sub));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> sub[i][0];
		int k = 2 * sub[i][0];
		for(int j = 1; j <= k; j++) {
			cin >> sub[i][j];
		}
	}
	int ans = 0x3f3f3f; //answer
	while(q--) {
		cin >> dx >> dy;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				//枚举每一组线路对（i，J)
				if(solution(i, j)) {
					ans = min(ans, same(i, j));
				}
			}
		}
		cout << ans + w[dx] + w[dy] << endl;
	}
	return 0;
}
