//呃啊，对拍发现结论伪了 D: 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define N (int)(2e6 + 5)
#define M (int)(1e6 + 5)
#define N1 (int)(5e3 + 5)
#define inf (int)(1e9)
#define mod (int)(1e9 + 7)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int Case, T = 1;
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = (ch == '-') ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
inline ll lread(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || '9' < ch){
		f = (ch == '-') ? -f : f;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
int n;
int to[N], dis[N1], cnt[N1];
ll d;
ll x[N];
void bfs(int s){
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	dis[s] = 0, cnt[s] = 1;
	qwe(u, s, n){
		qwe(v, u + 1, to[u]){
			if(dis[v] > dis[u] + 1) dis[v] = dis[u] + 1, cnt[v] = cnt[u];
			else if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
		}
	}
}
void Solve(){
	n = read(), d = lread();
	qwe(i, 1, n) x[i] = lread();
	qwe(i, 1, n){
		int l = i, r = n, res = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(x[mid] - x[i] <= d) l = mid + 1, res = mid;
			else r = mid - 1;
		}
		to[i] = res;
	}
	if(1 <= Case && Case <= 10){
		int ans = 0;
		qwe(i, 1, n){
			bfs(i);
	  		qwe(j, i, n) if(cnt[j] == 2) ans++;
		}
		printf("%d\n", ans);
		return; 
	}
	if(11 <= Case && Case <= 12){
//		if(T == 9){
//			printf("%d %lld\n", n, d);
//			qwe(i, 1, n) printf("%lld ", x[i]);
//			puts(""); 
//		}
		int len = to[1] - 1 + 1;
		if(len <= 2) puts("0");
		else printf("%d\n", max(0, n - len * 2 + 3));
		return;
	}
	if(13 <= Case && Case <= 14){
		
	}
}
int main(){
//	freopen("migrate4.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	Case = read(), T = read();
	while(T--) Solve();
	return 0;
} 
/*

Makka pakka :D
*/

