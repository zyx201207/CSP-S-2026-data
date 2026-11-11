#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	long long n, m, ans = 0, sum = 0, s = 0;
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	for (long long k = 0; k < n; k++) {
		for (long long i = k; i < n; i++) {
			
			for (long long j = k; j < i; j++) {
				sum += a[i] - a[j];
			}
			if (sum <= m) {
				ans++;
			} else {
				sum=0;
				continue;
			}
			sum = 0;
			
		}
	
		if (ans > s) {
			s = ans;
		}
		ans = 0;
	}


	cout << s;
	return 0;
}
