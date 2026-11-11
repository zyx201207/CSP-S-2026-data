#include<bits/stdc++.h>
#define w first 
#define v second 
using namespace std;
const int N = 5e5 + 10;
long long n, m, a[N], ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(n > 5000) {
		long long res = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			res += (a[i] - a[i - 1]) * cnt++; 
			if(res > m) {
				break;
			}
			ans++;
		}
		cout << ans++ << endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		long long res = 0, cnt = 0;
		for(int j = i; j <= n;j++) {
			res += (a[j] - a[j - 1]) * (j - i); 
			if(res > m)break;
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
