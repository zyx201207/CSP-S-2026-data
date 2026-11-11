#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, d = 0;
long long m;
long long a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int d = 1;
	for(int i = 1; i < n; i++){
		if(a[d+1]-a[d] <= m){
			m -= (a[d+1]-a[d])*d;
			for(int j = 1; j <= d; j++) a[j] = a[d+1];
			d++;
		}
	}
	int ans = 1;
	for(int i = 2; i <= n; i++){
		if(a[i] == a[i-1]) ans++;
	}
	cout << ans;
	return 0;
}