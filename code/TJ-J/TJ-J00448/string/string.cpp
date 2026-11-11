#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int N = 1e6 + 10;
int n;
struct point {
	int sz;
	string goal;
}num[N];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i ++ ) {
		cin >> num[i].sz >> num[i].goal;
	}
	
	int L = 1, R = n;
	int ans = 0;
	while(L < R) {
		int minx = min(num[L].sz, num[R].sz);
		if(num[L].goal != num[R].goal) ans += minx;
		num[L].sz -= minx;
		num[R].sz -= minx;
		
		if(!num[L].sz) L += 1;
		if(!num[R].sz) R -= 1;
	}
	
	cout << ans << "\n";
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t; t = 1;
	while(t -- ) solve();
	return 0;
}
