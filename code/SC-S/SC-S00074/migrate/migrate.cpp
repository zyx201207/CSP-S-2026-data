#include <bits/stdc++.h>
using namespace std;
int a[2000001], c = 0, z = 0, m = 1000000;
void mmm(int x, int y, int d){
	if (x == y){
		if (z < m){
			c = 1;
			m = z;
		}else if (m == z){
			c++;
		}
	}
	for (int i = x + 1; i <= y; i++){
		if (a[x] + d >= a[i]){
			z++;
			mmm(i, y, d);
			z--;
		}
	}
} 
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--){
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int cplus = 0;
		for (int i = 1; i <= n - 3; i++){
			for (int j = i + 3; j <= n; j++){
				c = 0, z = 0, m = 1000000;
				mmm(1, n, d);
				cplus += c;
			}
		}
		cout << cplus << endl;                                                                                    
	}
}
