#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define N (int)(5e5 + 5)
#define M (int)(1e6 + 5)
#define inf (ll)(1e18)
#define mod (int)(1e9 + 7)
#define qwe(i, l, r) for(int i = l; i <= r; i++)
#define ewq(i, r, l) for(int i = r; i >= l; i--)
#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
int T = 1;
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
int n, ans = 1;
ll m;
ll a[N], s[N];
inline bool check(int l, int r, ll tar){return tar * (r - l + 1) - (s[r] - s[l - 1]) <= m;}
void calc(int pos, ll tar){
	int l = 1, r = pos, res = -1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid, pos, tar)) r = mid - 1, res = mid;
		else l = mid + 1;
	}
	if(~res) ans = max(ans, pos - res + 1);
}
void Solve(){
	n = read(), m = lread();
	qwe(i, 1, n) a[i] = lread();
	sort(a + 1, a + n + 1);
	qwe(i, 1, n) s[i] = s[i - 1] + a[i];
	a[n + 1] = -inf;
	for(int i = 1, nxt; i <= n; i = nxt){
		nxt = i;
		while(a[i] == a[nxt]) nxt++;
		calc(nxt - 1, a[i]);
	}
	printf("%d", ans);
}
int main(){
//	freopen("crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	T = read();
	while(T--) Solve();
	return 0;
} 
/*

Makka pakka :D
*/

