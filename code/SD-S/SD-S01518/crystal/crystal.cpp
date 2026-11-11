#include<bits/stdc++.h>
using namespace std;
int n , ans = 0;
long long a[500005] , sum , m;
int l = 1;
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0); 
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		sum += (a[i] - a[i - 1]) * (i - l);
		while(sum > m) {
			sum -= (a[i] - a[l]);
			l++;
		}
		ans = max(ans , i - l + 1);
	}
	cout << ans;
	return 0;
}
