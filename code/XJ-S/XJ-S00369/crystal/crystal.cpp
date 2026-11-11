#include <bits/stdc++.h>
using namespace std;
int n, s, k;
long long m, ans, cnt;
long long a[500005];
long long c[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (i > 2){
			if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
				k++;
		}
	}
	sort(a + 1, a + n + 1);
	int q = a[(n + 1) / 2];
	for (int i = 1; i <= n; i++){
		if (k == n - 2)
			if ( m == ( a[i] / (a[2] - a[1]) - 1) * (a[i] / 2)){
				cout << i;
				return 0;
			}
		if (a[i] > q) break;
		c[i] = q - a[i];
		s++;
	}
	sort(c + 1, c + s + 1);
	for (int i = 1; i <= s; i++){
		if (ans + c[i] <= m){
			ans += c[i];
			cnt++;
		}
		else
			break;
	}
	while(ans <= m){
		s++;
		ans += (a[s] - q) * cnt;
		q = a[s];
		if (ans <= m) cnt++;
	}
	cout << cnt;
	return 0;
} 
