//SN-S00447 陈博煜 西安交通大学附属中学 
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 5e5 + 5;
long long a[MAXN], pfx[MAXN], m;
int n;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

bool check(int r, int len){
	int l = r - len + 1;
	return ((1ll * len * a[r] - (pfx[r] - pfx[l - 1])) <= m);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		pfx[i] = pfx[i - 1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int lo = 1, hi = i, mid;
		while(lo < hi)
			mid = (lo + hi + 1) >> 1,
			check(i, mid) ? lo = mid : hi = mid - 1;
		ans = max(ans, lo);
	}
	cout<< ans<< "\n";
	fclose(stdin), fclose(stdout);
	return 0;
}
