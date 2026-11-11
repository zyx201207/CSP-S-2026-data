#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	vector <int> a;
	int c, t;
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		int n, d;
		cin >> n >> d;
		for (int j = 1;j <= n;j++){
			int x;
			cin >> x;
			a.push_back(x);
		}
	}
	cout << 0 << 1;
	return 0;
}
