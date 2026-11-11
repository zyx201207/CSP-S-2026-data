#include <bits/stdc++.h>
using namespace std;
long long const N = 200005, M = 1073741824 - 1;
long long n, m;
long long a[N];
long long sum = M, ans;
bool flag, vis[N];

void xuan(long long x, long long y, long long cnt) {
	if (x == y) {
		xuan(x, y + 1, cnt);
	}
	if (cnt > m) {
		return ;
	}
	if (x > n) {
		flag = 1;
		return ;
	}
	if (flag) {
		return ;
	}
	if (!vis[y]) {
		sum = (sum & a[y] & a[x]);
		ans = max(ans, sum);
		vis[y] = 1;
		xuan(x, y + 1, cnt + 1);
		vis[y] = 0, sum = M;
	} else {
		xuan(x, y + 1, cnt);
		vis[x] = 0;
	}
	xuan(x + 1, 1, 1);
//	for(long long i=2;i<=x;i++){
//		if(!vis[i]){
//			sum=max(sum,sum&a[i]);
//			i++;
//		}else{
//			i++;
//		}
//	}
}

int main(void) {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	xuan(1, 1, 1);
	cout << ans;
	return 0;
}