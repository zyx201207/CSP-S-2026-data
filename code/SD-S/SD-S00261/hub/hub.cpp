#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

//#define LOCAL
namespace IO {
	#ifndef LOCAL
		#define SIZE (1<<20)
		char in[SIZE] , *p1=in , *p2=in , out[SIZE] , *p3 = out;
		#define getchar() (p1==p2 && (p2=(p1=in)+fread(in,1,SIZE,stdin)) , p1==p2 ? EOF : *p1 ++)
		#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
		#define putchar(c) (p3==out+SIZE && flush() , *p3 ++ = c)
		class Flush{ public: ~Flush() {flush();} } ___;
	#endif

	inline int read() {
		int x = 0 , f = 1;
		int c = getchar();
		while(c < '0' || '9' < c) {
			if(c == '-') f = -1;
			c = getchar();
		}
		while('0' <= c && c <= '9') {
			x = (x<<3) + (x<<1) + c - '0';
			c = getchar();
		}
		return x * f;
	}

	inline void write(int x , bool f = true) {
		if(x < 0) x = -x , putchar('-');
		static short stk[80]; int top = 0;
		do stk[++ top] = x%10 , x /= 10; while(x);
		while(top) putchar(stk[top --] | '0');
		if(f) putchar('\n'); else putchar(' ');
	}

	#ifndef LOCAL
		#undef SIZE
		#undef getchar
		#undef flush
		#undef putchar
	#endif
} using IO::read; using IO::write;

const int N = 15 , M = 25;

int n , k;
int h[N] , e[M] , ne[M] , idx;
bool used[N]; int p[N] , dis[N] , tmpdis[N];
int ans;

void add(int a , int b) {
	e[idx] = b , ne[idx] = h[a] , h[a] = idx ++;
}

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void dfs(int u , int fa) {
	for(int i = h[u] ; ~i ; i = ne[i]) {
		int v = e[i];
		if(v == fa) continue;
		tmpdis[v] = tmpdis[u]+1;
		dfs(v , u);
	}
}

void choose(int u , int cnt) {
	if(u > n) {
		if(cnt != k) return;
		for(int i = 1 ; i <= n ; i ++) p[i] = i;
		for(int i = 1 ; i <= n ; i ++) if(used[i]) {
			for(int j = h[i] ; ~j ; j = ne[j]) {
				int v = e[j];
				if(used[v] && find(i) != find(v)) p[find(i)] = find(v);
			}
		}
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++) if(used[i] && p[i] == i) cnt ++;
		if(cnt > 2) return;
		
		memset(dis , 0x3f , sizeof dis);
		for(int i = 1 ; i <= n ; i ++) if(used[i]) {
			tmpdis[i] = 0;
			dfs(i , 0);
			for(int j = 1 ; j <= n ; j ++) {
				dis[j] = min(dis[j] , tmpdis[j]);
			}
		}
		int res = 0;
		for(int i = 1 ; i <= n ; i ++)
			res = max(res , dis[i]);
		ans = min(ans , res);
		return;
	}
	
	if(n-u >= k-cnt) choose(u+1 , cnt);
	if(cnt < k) {
		used[u] = true;
		choose(u+1 , cnt+1);
		used[u] = false;
	}
}

void solve() {
	n = read(); k = read();
	memset(h , -1 , sizeof h);
	for(int i = 1 ; i < n ; i ++) {
		int a = read() , b = read();
		add(a , b); add(b , a);
	}
	ans = 0x3f3f3f3f;
	choose(1 , 0);
	write(ans);
}

int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int C = read() , T = read();
	while(T --) {
		if(C <= 3) solve();
	}
	return 0;
}

