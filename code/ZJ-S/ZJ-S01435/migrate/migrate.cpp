#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long c, t, n, m;
long long a[N];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i++)cin >> a[i];
		if(a[n] - a[1] < m){
			cout << 0 << '\n';
			continue;
		}
		cout << 1 << '\n';
	}
	return 0;
}
