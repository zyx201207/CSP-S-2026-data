#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[n];
	int desk[n], head; // 当局桌面上牌的状态 
	int b[m + 1];      // 当局桌面上的点数状态 
	int c[m + 1];      // 所有游戏中点数保留次数 
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		head = 0;
		for (int j = 1; j <= m; j++) b[j] = -1;
		
		for (int j = i; j < n; j++) {
			if (b[a[j]] == -1) {
				desk[head] = a[j];
				b[a[j]] = head;
				head++;
			} else {
				for (int k = b[a[j]]; k < head; k++) {
					b[desk[k]] = -1;
				}
				head = b[a[j]];
				desk[head] = a[j];
				b[a[j]] = head;
				head++;
			}
		}
		
		for (int j = 0; j < head; j++) {
			c[desk[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << c[i] << ' ';
	return 0;
}
