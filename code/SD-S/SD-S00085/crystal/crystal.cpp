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

const int N = 5e5+5;
ll n, m;
ll a[N];
ll s[N];

ll sum(int l, int r) {
	return (s[r] - s[l-1]);
}

int check(int pos) {
	int l = 1, r = pos+1;
	int ret = -1;
	while(l <= r) {
		int mid = (l+r)/2;
		int len = pos - mid +1;
		if(m >= a[pos]*len - sum(mid, pos)) {
			ret = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	return ret;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fr(n, m);
	for(int i = 1; i <= n; i++) fr(a[i]);
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) s[i] = s[i-1]+a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, i - check(i)+1);
	}
	cout << ans << '\n';
	
}





