#include <bits/stdc++.h>
using namespace std;

int sum, cnt;
struct string {
	int num;
	char c;
}a[200005];
int main () {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
		sum += a[i].num;
	}
	
	int zj = 0;
	zj = sum / 2 + 1;
	int zh = 0;
	
	for (int i = n; zh < (sum - zj + 1); i--) {
		zh = a[i].num;		
		if (zh >= (sum - zj + 1)) break;
		for (int j = a[i].num; j >= 1; j++) {
			
			int xuhao = sum - zh - j + 1;
			int xd = sum - xuhao + 1;
			
			int k1 = 0;
			while (xuhao > 0) {
				k1++;
				if (xuhao < a[k1].num) {
					break;
				}
				xuhao -= a[k1].num;
			}
			int k2 = 0;
			while (xd > 0) {
				k2++;
				if (xd < a[k2].num) {
					break;
				}
				xd -= a[k2].num;
			}
			if (a[k1].c != a[k2].c) cnt++;
			// cout << i << " a[xd].c:" << a[xd].c << " a[i].c:" << a[i].c << "\n";		
				
		}
	}
	
	cout << cnt << "\n";
	return 0;
}
