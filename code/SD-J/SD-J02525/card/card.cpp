#include <bits/stdc++.h>
using namespace std;
int n, m, ans1, ans2;
const int N = 1e5 + 3;
int a[N];
map<int, int>mp;
bool op = false;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	if(n <= 5 && m <= 2) op = true;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i - 1] > a[i])op = true;
	}
	if(op) {
		for(int i = 1; i <= n; i++) {
			int v1 = 0, v2 = 0;
			for(int j = i; j <= n; j++) {
				if(v1 && a[j] == 1 ) {
					for(int b = v1; b < j; b++) ans1 -= (a[b] == 1), ans2 -= (a[b] == 2);
					v1 = j;
						if(v2 && a[j] == 2) {
						for(int b = v2; b < j; b++) ans1 -= (a[b] == 1), ans2 -= (a[b] == 2);
						v2 = j;
						}
				if(v1 = 0 && a[i] == 1 ) v1 == i;
				if(v2 == 0 && a[j] == 2)v2 = j;
				ans1 += (a[j] == 1), ans2 += (a[j] == 2);
				}
			}
		}
	}
	cout << ans1 << ans2 << endl;
	return 0;
} 
