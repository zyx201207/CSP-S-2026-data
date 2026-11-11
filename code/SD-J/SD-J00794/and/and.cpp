#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n;
	long long k;
	cin >> n >> k;
	long long d[100010];
	int a[100010];
	long long ans = 0;
	for(long long i = 0; i < n; i++){
		cin >> d[i];
	}
	sort(d, d+n);
	ans = d[n-1];
	
	for(int i = 0; i < k-1; i++){
		ans = ans&d[n-i-2];
	}
	cout << ans;

	return 0;
}

