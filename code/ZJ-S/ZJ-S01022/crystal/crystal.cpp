#include <bits/stdc++.h>
using namespace std;

long long n, m, cnt, sum;
long long a[500008], maxx; 

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	cnt = 0, sum = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	sort(a, a + n + 1);
	for(int i = 1;i <= n;i++) {
		cout << a[i];
	}
	
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			if(a[i] == a[j]) {
				break;
			}
		}
		maxx = max(maxx, sum);
	}
	cout << 5;
	return 0;
}
