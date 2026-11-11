// 24 pt - 40 pt.
// Ridiculous.
// I am screwed.
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
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

int c, t;
int n;
long long d;
long long ans;
long long f[2000005], a[2000005], g[2000005];

int main(void) {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(c); read(t);
	while(t--) {
		ans=0;
		read(n); read(d);
		for(int i = 1; i <= n; ++i) read(a[i]);
		for(int i = 1; i <= n; ++i) {
			for(int j = i+1; j <= n; ++j) f[j]=0, g[j]=0x3f3f3f3f3f3f3f3f;
			f[i]=1; g[i]=0;
			for(int j = i; j <= n; ++j) {
//				printf("%d %d %d %d %d\n", i, j, ans, f[j], g[j]);
				if(f[j]==2) ++ans;
//				if(f[j]>2) break;
				for(int k = j+1; k <= n; ++k) {
					if(a[k]-a[j]>d) break;
					if(g[k]==g[j]+1) f[k]+=f[j];
					else if(g[k]>g[j]+1) f[k]=f[j], g[k]=g[j]+1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
