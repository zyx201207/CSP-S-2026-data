#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500010];
int main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	long long l = 1 , r = 1;
	long long ans = 0;
	long long cost = 0 , have_cost = 0;
	while(r <= n){
		ans = max(ans , r - l + 1);
		r++;
		have_cost += a[r] - a[r - 1];
		cost += (r - l) * (a[r] - a[r - 1]);
		while(cost > m && l < r){
			l++;
			cost -= have_cost;
			have_cost -= a[l] - a[l - 1];
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
