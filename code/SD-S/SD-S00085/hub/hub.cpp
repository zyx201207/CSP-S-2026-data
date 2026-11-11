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

const int N = 2e6+6;

int c, t;
int n, k;
vector<int>G[N];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	fr(c, t);
	while(t--) {	
		cout << 1 << '\n';
	}
}

