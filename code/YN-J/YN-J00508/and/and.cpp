#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long N = 2e5 + 10;
long long a[N];
long long o[N], v[N];
long long s;

void dfs(long long x, long long y) {
	if (x > m) {
		long long t = a[1];
		for (long long i = 1; i <= m; i++) {
			cout << a[i] << " ";
			t = t & a[i];
		}
		cout << endl << t << endl;
		s = max(s, t);
		cout << s << endl;
		return;
	}
	for (long long i = y; i <= n; i++) {
		if (v[i] == 0) {
			a[x] = o[i];
			v[i] = 1;
			dfs(x + 1, i);
		}

		a[x] = 0;
		v[i] = 0;
	}
}

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long h;
	for (long long i = 1; i <= n; i++) {
		cin >> o[i];
		if (i == 1) {
			h = o[i];
		} else {
			h = h & o[i];
		}
	}
	if(n==m){
		cout<<h<<endl;
	}else{dfs(1, 0);
	cout << s << endl;
	}
	


	return 0;
}
