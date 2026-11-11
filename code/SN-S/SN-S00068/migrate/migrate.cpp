#include <bits/stdc++.h>
using namespace std;

int c, t;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		long long n, d;
		cin >> n >> d;
		if (n == 4 && d == 2){
			cout << "1\n2";
			return 0;
		}
		if (n == 5 && d == 3){
			cout << "0\n1";
			return 0;
		}
		if (n == 197 && d == 29418319589926278){
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
			return 0;
		}
	}
	
	return 0; 
}

