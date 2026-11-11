#include<bits/stdc++.h> 
using namespace std;
int n, m, card[200003];
int main() {
	freopen("card.in","r", stdin);
	freopen("card.out","w", stdout);
	cin >>n >>m;
	int mmm = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
		
	}
	for (int i = 1; i <= n; i++) {
		if (card[i] == mmm) {
			cnt++;
		} else {
			if (i!=1) {
				
				if (cnt <= n) {
					cout << cnt <<' ';
				} else {
					cout << n << ' ';
				}
			}
			mmm = card[i];
			cnt = 1;
		}
	}
	if (cnt <= n) {
		cout << cnt << ' ';
	} else {
		cout << n << ' ';
	}
	return 0;
}
