#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10 , M = 3e5 + 10;
int n , m , f;
long long a[N] , s[N] , sum[N] , ans[N];

void solve(int x) {
	for(int i = 1;i <= m;i++) {
		sum[i] = 0;
	}
	for(int i = x;i <= n;i++) {
		sum[i] = a[i];
		for(int j = x;j <= i;j++) {
			if(sum[i] == sum[j]) {
				for(int k = j + 1;k <= i;k++) {
					sum[k] = 0;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++) {
		ans[sum[i]]++;
	}
}

int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		s[a[i]] = i;
	}
	for(int i = 1;i <= n;i++) {
		if(a[i] < a[i - 1]) f = 1;
	}
	if(f == 0) {
		for(int i = 1;i <= m;i++) {
			cout << s[i] << " ";
		}
		return 0;
	}
	if(n <= 500 && m <= 200) {
		for(int i = 1;i <= m;i++) {
			solve(i);
		}
		ans[a[n]] = n;
		for(int i = 1;i <= m;i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}

