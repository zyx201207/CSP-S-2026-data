#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned ll
const int BUFSI = 1<<20;
static char buf[BUFSI], *bg = buf, *ed = buf;
inline int gc() {
	if(bg == ed) {
		bg = buf;
		ed = buf + fread(buf, 1, BUFSI, stdin);
	}
	if(bg == ed) return  EOF;
	return *bg++;
} 
template<typename T>
bool fr(T &x) {
	x = 0;
	int ch = gc(), sgn = 0;
	while(ch != EOF && !isdigit(ch)) {
		sgn |= ch == '-';
		ch = gc();
	}
	if(ch == EOF) return 0;
	while(ch != EOF && isdigit(ch)) {
		x = x*10 + ch - '0';
		ch = gc();
	}
	if(sgn) x = -x;
	return 1;
}
bool fr(string &x) {
	x.clear();
	int ch = gc();
	while(ch != EOF && isspace(ch)) ch = gc();
	if(ch == EOF) return 0;
	while(ch != EOF && !isspace(ch)) {
		x += ch;
		ch = gc();
	}
	return 1;
}
template<typename T, typename ...A>
bool fr(T &x, A &...a) {
	bool ok = 1;
	ok &= fr(x);
	ok &= fr(a...);
	return ok;
}

const int N = 2e6+5;
int c, T;
ll n, d;

ll a[N];
ll cnt[N];
ll mx[N], num[N];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fr(c, T);
	while(T--) {
		fr(n, d);
		for(int i = 1; i <= n; i++) fr(a[i]);
		memset(cnt, 0, sizeof(ll) * (n+2));
		memset(mx, 0, sizeof(ll) * (n+2));
		memset(num, 0, sizeof(ll) * (n+2));
		int nxt = 1;
		for(int i = 1; i <= n; i++) {
			while(a[nxt+1] -a[i] <= d && nxt < n) nxt++;
			mx[i] = nxt;
			if(i >= 3) num[i] = max(1LL*i,mx[i-1]) - max(1LL*i, mx[i-2]);
			if(nxt != i)cnt[nxt] += cnt[i]+1;
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++) ans += cnt[i] * num[i];
		cout << ans << '\n';
	}
	
}

