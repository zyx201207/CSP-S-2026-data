#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

long long n, m, a[N], ans;


int main(){
	freopen("crystal.in", "r" , stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	long long l = n, sum = 0;
	for(int r = n; r >= 1; r--){
		while(l - 1 > 0 && sum + a[r] - a[l - 1] <= m){
			l--;
			sum = sum + a[r] - a[l];
		}
		ans = max(ans, r - l + 1);
		sum = 1LL * sum - 1LL * (r - l) * (a[r] - a[r - 1]);
		
	}
	cout << ans;
	return 0;
}

