#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	int n = rand() % 6 + 1, m = rand() % 9 + 2, q = rand() % 8 + 1;
	cout << "0 " << n << " " << m << " 20 " << q << "\n";
	for(int i = 1; i <= m; i++){
		int x = rand() % 10 + 1;
		cout << x << " ";
	}
	cout << "\n";
	for(int i = 1; i <= n; i++){
		int k = rand() % 5 + 1;
		cout << k << " ";
		for(int j = 0; j < k; j++){
			int x = rand() % m + 1, w = rand() % 10 + 1;
			cout << x << " " << w << " ";
		}
		cout << "\n";
	}
	for(int i = 1; i <= q; i++){
		int x = rand() % m + 1, y = rand() % m + 1;
		while(x == y) x = rand() % m + 1, y = rand() % m + 1;
		cout << x << " " << y << "\n";
	}
	
	return 0;
}
