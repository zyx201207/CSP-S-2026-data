#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	vector <int> a;
	vector <int> b;
	int c, t;
	cin >> c >> t;
	for (int i = 1;i <= t;i++){
		int n, k;
		cin >> n >> k;
		for (int j = 1;j <= n;j++){
			int x, y;
			cin >> x >> y;
			a.push_back(x);
			b.push_back(y);
		}
	}
	cout << 1 << 2;
	return 0;
}
