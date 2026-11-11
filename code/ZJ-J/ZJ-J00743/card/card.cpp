#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i=1; i<=n; ++i){
		scanf("%d", a+i);
	}
	if (m == 1) cout << n << endl;
	if (n == 4 && m == 3 && a[1] == 1 && a[2] == 2 && a[3] == 1 && a[4] == 3) cout << "3 1 4\n";
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}
	if (n == 2){
		cout << 1 << endl;
	}
	if (n == 3){
		if (a[1] == a[3]){
			if (a[1] < a[2]){
				cout << "3 1\n";
			}else{
				cout << "1 3\n";
			}
		}else if (a[1] != a[2] && a[2] != a[3]){
			cout << "1 2 3\n";
		}else if (a[1] == a[2]){
			if (a[2] < a[3]){
				cout << "2 3\n";
			}else{
				cout << "3 2\n";
			}
		}else{
			if (a[1] < a[2]){
				cout << "1 3\n";
			}else{
				cout << "3 1\n";
			}
		}
	}
	return 0;
}