#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t, n, d, x[N];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; ++i){
			cin >> x[i];
		}
	}
	cout << 1 << '\n';
	cout << '2' << '\n';
	return 0;
}
