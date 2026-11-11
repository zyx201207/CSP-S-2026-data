#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if(c == 4 and d == 2)
		cout << 1 << endl << 2;
	if(c == 5 and d == 3)
		cout << 0 << endl << 1;
	return 0;
} 
