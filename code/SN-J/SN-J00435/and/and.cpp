#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,maxr=-1;
vector<ll> a;
vector<bool> b;
deque<ll> c;

void dfs(ll need) {
	if (need == 0) {
		ll res = 0xffffffff;
		for (ll i=0;i<c.size();i++) {
			res &= a[c[i]];
		}
		if (res > maxr) {
			maxr = res;
		}
	}
	for (ll i=0;i<n;i++) {
		if (!b[i]) {
			b[i] = true;
			c.push_back(i);
			dfs(need-1);
			c.pop_back();
			b[i] = false;
		}
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> k;
	a.resize(n);
	b.resize(n);
	for (ll i=0;i<n;i++) {
		cin >> a[i];
	}
	
	for (ll i=0;i<n;i++) {
		b[i] = true;
		c.push_back(i);
		dfs(k-1);
		c.pop_back();
		b[i] = false;
	}
	cout << maxr;
	return 0;
}


