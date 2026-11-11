#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n;
	cin >> n;
	long long m;
	cin >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if(a[1] == a[2]){
		cout << n;
		return 0;
	}
	long long c = a[2] - a[1];
	
	long long ans = 1;

	long long f = m / c;
	int cnt = 1;
	while(f - cnt >= 0){
		f -= cnt;
		ans++;
		cnt++;
	}
	cout << ans;
	
	return 0;
}