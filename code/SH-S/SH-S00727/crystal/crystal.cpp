#include<bits/stdc++.h>
using namespace std;
long long n, m, in, a[500010], c[500010];

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(long long i = 1; i < n; i++){
		a[i] = a[i] + a[i-1];
	}
	for(long long i = 1; i < n; i++){
		c[i] = i * (a[i]-a[i-1]) - a[i-1];
	}
	for(long long i = n-1; i >= 0; i--){
		if(c[i] <= m){
			cout << i+1 << endl;
			return 0;
		}
	}
}
