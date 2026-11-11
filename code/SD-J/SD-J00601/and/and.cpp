#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 1;

struct Node {
	ll h;
	bool b[32];
}a[N];

int n, m;
bool B=1,A=1;
ll ans, t[32], f[32], maxx;

bool cmp(Node aa, Node bb) {
	return aa.h > bb.h;
}

void dfs(int x, int k, ll sum) {
	if(k == m) {
		ans = max(ans,sum);
		return ;
	}
	if(n-x < m-k) return ;
	dfs(x+1,k,sum);
	if(sum) dfs(x+1,k+1,sum&(a[x+1].h));
	else dfs(x+1,k+1,(a[x+1].h));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].h;
		ll x = a[i].h;
		if(x != i-1) B = 0;
		if(!(x == pow(2,log2(x)+1)-1)) A = 0;
		maxx = max(maxx,x);
		while(x) {
			int lg = log2(x);
			ll pw = pow(2,lg);
			t[lg]++;
			a[i].b[lg] = 1;
			x -= pw;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(n <= 20) {
		dfs(1,0,0);
		dfs(1,1,a[1].h);
		cout << ans;
		return 0;
	}
	if(m == 1) {
		cout << a[1].h;
		return 0;
	}
	if(m == n) {
		ans = a[1].h;
		for(int i = 2; i <= n; i++) ans = ans&(a[i].h);
		cout << ans;
		return 0;
	}
	if(m == 2) {
		for(int i = 31; i >= 0; i--) {
			if(t[i] < 2) continue;
			for(int j = 1; j <= n; j++) {
				if(a[j].b[i]) {
					cout << ((a[j].h)&(a[j+1].h));
					return 0;
				}
			}
		}
	}
	if(maxx < 4) {
		ans = a[1].h;
		for(int i = 2; i <= m; i++) ans = ans&(a[i].h);
		cout << ans;
		return 0;
	}
	if(A) {
		cout << a[m].h;
		return 0;
	}
	if(B) {
		ans = a[1].h;
		for(int i = 2; i <= m; i++) ans = ans&(a[i].h);
		cout << ans;
		return 0;
	}
	return 0;
}

