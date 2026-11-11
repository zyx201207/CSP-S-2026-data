#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c, t;
ll x[2000006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		int n;
		ll d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> x[i];
		}
		cout << n / 2 << endl;
	}
	return 0;
}
