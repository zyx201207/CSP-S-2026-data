#include<bits/stdc++.h>
using namespace std;
int a[500005], n, m, ans;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++){
		if(m >= a[i + 1] - a[i]){ans++, m -= a[i + 1] - a[i];}
	}
	cout << ans;
	return 0;
}

