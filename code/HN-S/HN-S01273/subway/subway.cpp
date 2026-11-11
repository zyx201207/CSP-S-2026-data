#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10; 
inline int read(){
	int x = 0, y = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-'){
			y = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * y;
}
int n, m, d, q, a[N], l, b[10001][10001], c[10001][10001][2], len[10001], f[10001];
long long minn;
void work(int x, int y, long long ans, int f[]){
	if(ans > minn){
		return;
	}
	for(int i = 1; i <= len[x]; i++){
		if(f[c[x][i][0]] == 1){
			continue;
		}
		if(c[x][i][0] == y){
			minn = min(ans+c[x][i][1], minn);
		}
		f[c[x][i][0]] = 1;
		work(c[x][i][0], y, ans+c[x][i][1], f);
		f[c[x][i][0]] = 0;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int ccc = read();
	n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++){
		a[i] = read();
	}
	for(int i = 1; i <= n; i++){
		l = read();
		int x[l], y[l];
		for(int j = 1; j <= l; j++){
			x[j] = read();
			y[j] = read();
		}
		for(int j = 1; j <= l; j++){
			for(int k = 1; k <= l; k++){
				if(j == k){
					continue;
				}
				if(b[x[j]][x[k]] != 0){
					b[x[j]][x[k]] = min(b[x[j]][x[k]], y[j] + y[k]);
					b[x[k]][x[j]] = b[x[j]][x[k]];
				}else{
					b[x[j]][x[k]] = b[x[k]][x[j]] = y[j] + y[k];
				}
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			if(i == j){
				continue;
			}
			if(b[i][j] != 0){
				len[i]++;
				c[i][len[i]][0] = j;
				c[i][len[i]][1] = b[i][j];
			}
		}
	}
	while(q--){
		int x = read(), y = read();
		minn = 1e9+1;
		for(int i = 1; i <= 10000; i++){
			f[i] = 0;
		}
		f[x] = 1;
		work(x, y, 0, f);
		cout << minn + a[x] + a[y] << '\n';
	}
	return 0;
}
