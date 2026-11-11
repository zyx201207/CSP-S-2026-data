#include <bits/stdc++.h>
using namespace std;

const int N = 1 + 5;

int c, t, x, y, a;

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	
	while (t -- ){
		cin >> x >> y;
		for (int i = 1; i <= x; i ++ ) cin >> a;
		cout << y / 2 + y % 2 << '\n';
	}
	
	return 0;
}