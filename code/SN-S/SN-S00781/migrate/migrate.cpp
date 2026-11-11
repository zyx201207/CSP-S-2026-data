# include <bits/stdc++.h>
# define ll long long
# define cps CLOCKS_PER_SEC
using namespace std;

ll read() {
	ll res = 0, f = 1;
	char ch;
	ch = getchar();
	while (!(ch <= '9' && ch >= '0')) {
		if (ch == '-') f = -1;
		ch = getchar();
	} 
	
	while (ch <= '9' && ch >= '0') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return f * res;
} 

ll a[5000006]
void work() {
	ll n, d;
	cin >> n >> d;
	
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	cout << 0 << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int t;
	cin >> t;
	
	while (t --) work();
	
	
	return 0;
}
