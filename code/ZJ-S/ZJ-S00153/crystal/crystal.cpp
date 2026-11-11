// 100 pt.(expected so)
// O(nlogn).
// Why it's binary search? I don't even have the confidence to make sure it's not buggy...
// I bet the huge data is huge enough.
// domo, Ayanami_404 desu. Luogu UID: 983943.
// You know that I've always wanted to be part of the mihuoxingweidashang.
#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;
#define gc getchar

template <typename T>
void read(T &x) {
	x=0; char c;
	T f=1;
	while(!isdigit(c=gc())) if(c=='-') f=-1;
	while(isdigit(c)) x=x*10+c-'0', c=gc();
	x*=f;
	return ;
}

template <typename T>
T read() {
	T x; read(x); return x;
}

int n, ans=1;
long long m;
long long a[500005], s[500005];
//long long g[500005];

int main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(a[i]);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i) s[i]=s[i-1]+a[i];
	for(int i = 2; i <= n; ++i) {
		// a[i]*(i-j)-s[i-1]+s[j-1] <= m
//		printf(" %d\n", a[i]);
//		for(int j = i; j; --j) {
//			printf("%d\n", a[i]*(i-j)-s[i-1]+s[j-1]);
//		}
		int l=1, r=i;
		while(r > l) {
			int j=(l+r)>>1;
			long long d=a[i]*(i-j)-s[i-1]+s[j-1];
//			printf("%d %d %d %d\n", l, r, j, d);
			if(d<=m) r=j;
			else l=j+1;
		}
//		g[i]=r-1;
//		printf("%d\n", r);
//		puts("");
		ans=max(ans, i-r+1);
//		printf(" %d\n", g[i]);
	}
	printf("%d", ans);
	
	return 0;
}
