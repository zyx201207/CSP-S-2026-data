#include<bits/stdc++.h>
const int SZ = 1 << 16;
char ib[SZ], *is = ib, *it = ib, ob[SZ], *os = ob, *ot = ob + SZ, ostk[50];
#define Flush() (fwrite(ob, 1, os - ob, stdout), os = ob)
#define gc() (((is == it) && (it = ib + fread(is = ib, 1, SZ, stdin))), ((is == it) ? EOF : *is++))
#define pc(ch) (((os == ot) && Flush()), *os++ = ch)
#define END return Flush(), fflush(stdout), fclose(stdin), fclose(stdout), 0
typedef long long ll;
template <typename T> inline void read(T &x){
	x = 0;
	int ch = gc();
	bool flg = false;
	while((ch < '0' || ch > '9') && ch != EOF){
		flg |= ch == '-';
		ch = gc();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + (ch ^ 48);
		ch = gc();
	}
	x = flg ? -x : x;
}
template <typename T> inline void write(T x, char c = 0){
	if(x == 0){
		pc('0');
		if(c) pc(c);
		return;
	}
	if(x < 0){
		pc('-');
		x = -x;
	}
	int top = 0;
	while(x){
		ostk[++top] = (x % 10) | 48;
		x /= 10;
	}
	while(top) pc(ostk[top--]);
	if(c) pc(c);
}
// #undef DEBUG
// #undef STDIO
#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
const int N = 510, M = 5e5 + 10, D = 30;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, ptr[M];
ll w[M], dis[N][N];
struct node{
	int i;
	ll t;
}l[M][D];
int main(){
	#ifndef STDIO
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	#endif
	memset(dis, 0x3f, sizeof dis);
	read(c), read(n), read(m), read(d), read(q);
	for(int i = 1; i <= m; i++){
		read(w[i]);
	}
	for(int i = 1; i <= n; i++){
		int k;
		read(k);
		for(int j = 1; j <= k; j++){
			int a, t;
			read(a), read(t);
			l[a][++ptr[a]] = node{i, t};
		}
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int p = 1; p <= ptr[i]; p++){
			for(int q = 1; q <= ptr[i]; q++){
				dis[l[i][p].i][l[i][q].i] = std::min(dis[l[i][p].i][l[i][q].i], l[i][p].t + l[i][q].t);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int u, v;
		read(u), read(v);
		ll ans = INF;
		for(int p = 1; p <= ptr[u]; p++){
			for(int q = 1; q <= ptr[v]; q++){
				ans = std::min(ans, dis[l[u][p].i][l[v][q].i] + l[u][p].t + l[v][q].t);
			}
		}
		ans += w[u] + w[v];
		write(ans, '\n');
	}
	END;
}