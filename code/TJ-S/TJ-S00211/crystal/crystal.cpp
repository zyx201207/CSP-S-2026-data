#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	long long n , m;
	cin >> n >> m;
	long long cnt = 0;
	long long maxn = -1;
	long long temp = m;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(long long i = 2; i <= n - 1; i++) {
		cnt = 0;
		temp = m;
		for(long long j = 1; j <= n; j++) {
			if(a[i] == a[j]) {
				cnt++;
			}
			if(a[i] > a[j] && temp - a[i] + a[j] >= 0) {
				cnt++;
				temp -= a[i];
				temp += a[j];
			}
			if(cnt > maxn) {
				maxn = cnt;
			}
		}
	}
	cout << maxn;
	return 0;
}
