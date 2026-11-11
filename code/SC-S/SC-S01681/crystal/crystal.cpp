#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 100 , mod = 1e9 + 7;
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
int n , m , a[maxn] , sum[maxn] , ans;
signed main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	n = read();
	m = read();
	for(int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1 , a + 1 + n);
	int l = 1;
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
		while(l < i && (i - l + 1) * a[i] - (sum[i] - sum[l - 1]) > m) l++;
		ans = max(ans , i - l + 1);
	}
	writeh(ans);
	return 0;
}
/*
14:32 开始看题
14:40 打完
首先发现最后在能量值一定是在a_i中
然后我们发现优先加上离最后能量值更近的a_i
能量值只增不减
能覆盖的区间单调不降
用指针维护即可

愿此行，终抵群星！
*/