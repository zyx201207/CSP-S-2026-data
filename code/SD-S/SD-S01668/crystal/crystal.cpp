#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll qread() {
	bool b = true;
	ll x = 0;
	char ch = getchar();
	while(ch<'0' || ch>'9') {
		if('-' == ch) b = false;
		ch = getchar();
	}
	while(ch>='0' && ch<='9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return b ? x : -x;
}

const int maxN = 5e5 + 10;
//ll a[maxN], d[maxN];
ll n, m, ans;

struct node {
	ll x, d, t;
	
	bool operator < (node a) const {
		return x < a.x;
	}
	bool operator > (node a) const {
		return x > a.x;
	}
	
	node() : x(0), d(0), t(1) {}
	node(ll x, ll d, ll t) : x(x), d(d), t(t) {} 
	~node() {}
} a[maxN];

int main() { //crystalÄ£Äâ 3/4 14:53 45'
	ios::sync_with_stdio(false);
	cin.tie(); cout.tie();
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = qread(), m = qread();
	for(int i=1; i<=n; i++) a[i].x = qread(), a[i].d = a[i].x - a[i-1].x;
	sort(a+1, a+n+1);
//for(int i=1; i<=n; i++) cout << a[i].x << ' ';
//cout << endl;
	
	for(int i=n; i>=1; i--) {
		int j = i, cur = m;
		while(--j) if(cur >= a[i].x-a[j].x) a[i].t++, cur -= a[i].x-a[j].x;
		ans = max(ans, a[i].t);
//cout << i << ':' << ans << endl;
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

/*
#1
5 5
1 2 4 8 9

3
#2
5 8
-3 -1 2 2 7

4
*/
