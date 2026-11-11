#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	long long ans = 0;
	cin >> n >> m;
	long long a[500010];
	long long i;
	for(i = 0; i < n; i ++) {
		cin >> a[i];
	}
	long long des = n/2;
	long long pre = des - 1, aft = des + 1;
	sort(a, a + n);
	while (m > 0){
		if(a[aft] - a[des] <= m && a[des] - a[pre] > a[aft] - a[des] && aft < n){
			m -= a[aft] - a[des];
			a[aft] = a[des];
			aft++;
			ans++;
		} 
		else if(a[des] - a[pre] <= m && pre >= 0){
			m -= a[des] - a[pre];
			a[pre] = a[des];
			pre--;
			ans++;
		}
		else{
			break;
		}
	}
	cout << ans+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
