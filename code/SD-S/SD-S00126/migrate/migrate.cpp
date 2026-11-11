#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t, n;
long long d, x[N];
long long read() {
	long long res = 0, flag = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') flag = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * flag;
}
int ans = 1e9, num[N];
void dfs(int deep, int bgin, long long pos, int end) {
	if(bgin > end && pos == x[end]) {
		ans = min(deep, ans);
		num[ans]++;
		return ;
	}
	bool flag = 0;
	for(int i = bgin; i <= end; i++) {
		if(abs(x[i] - pos) <= d) {
			flag = 1;
			dfs(deep + 1, i + 1, x[i], end);
		}
	}
	if(!flag) return ;
}
long long cnt = 0;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n;
		d = read();
		for(int i = 1; i <= n; i++) x[i] = read();
//		cout << ans << "\n";
		if(n <= 9) {
			long long res = 0;
			for(int i = 1; i <= n ; i++) {
				for(int j = i; j <= n; j++) {
					for(int k = 1; k <= n; k++) num[k] = 0; 
					ans = 1e9, cnt = 0;
					dfs(0, i, x[i], j);
					if(ans != 1e9 && num[ans] == 2) res++;
				}
			}
			cout << res << "\n";
		} 
		else {
			cout << "0\n";
		}
	}
	return 0; 
} 
