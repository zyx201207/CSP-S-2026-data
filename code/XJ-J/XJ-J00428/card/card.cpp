#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5, M=3e5+5;
int n, m;
int a[N];
int cnt[M];
int fir[M]; //fir[x] 表示数字x第一次出现的位置。
int d[N]; //d[i] 表示查分数组
int ans[M]; //表示答案数组 
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		++ cnt[a[i]];
		fir[a[i]] = i;
	}
	for(int i=1; i<=n; ++i) {
		d[1] --; d[i] ++; //([1, i-1])
		d[i] --; d[fir[a[i]]] ++;  //([i, fir[ai]-1])
	}
	int p=0;
	for(int i=1; i<=n; ++i) {
		p += d[i];
 		ans[a[i]] += p;
	}
	for(int j=1; j<=m; ++j) {
		cout << cnt[j]*n+ans[j] << ' ';
	}
}
