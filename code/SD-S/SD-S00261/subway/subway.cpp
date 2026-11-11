#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

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

	inline void write(LL x , bool f = true) {
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

struct Zhan {
	int id; LL t;
};

const int N = 510 , M = 5e5+10;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int m , n , q;
LL w[M];
vector<Zhan> zhans[M];
LL dis[N][N];

inline LL min(LL x , LL y) {
	return x < y ? x : y;
}

int main() {
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int C = read(); n = read(); m = read(); int D = read(); q = read();
	for(int i = 1 ; i <= m ; i ++) w[i] = read();
	for(int id = 1 ; id <= n ; id ++) {
		int k = read();
		while(k --) {
			int x = read(); LL t = read();
			zhans[x].push_back({id , t});
		}
		for(int j = 1 ; j <= n ; j ++) dis[id][j] = INF;
		dis[id][id] = 0;
	}
	for(int i = 1 ; i <= m ; i ++) {
		for(int j = 0 ; j < (int)zhans[i].size() ; j ++) {
			int idj = zhans[i][j].id; LL tj = zhans[i][j].t;
			for(int k = 0 ; k < j ; k ++) {
				int idk = zhans[i][k].id; LL tk = zhans[i][k].t;
				dis[idj][idk] = dis[idk][idj] = min(dis[idj][idk] , tj+tk);
			}
		}
	}
	for(int k = 1 ; k <= n ; k ++) {
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j < i ; j ++) {
				dis[i][j] = dis[j][i] = min(dis[i][j] , dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q --) {
		int x = read() , y = read();
		LL ans = INF;
		for(auto i : zhans[x]) {
			for(auto j : zhans[y]) {
				ans = min(ans , i.t+j.t+dis[i.id][j.id]);
			}
		}
		ans += w[x]+w[y];
		write(ans);
	}
	return 0;
}

