#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500001]; 
long long f[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	f[1] = 0;
	int low = 1;
	int ans = -1;
	for(int i = 2;i <= n;i++){
		f[i] = f[i - 1] + (i - low) * (a[i] - a[i - 1]);
		while(f[i] > m){
			f[i] -= a[i] - a[low];
			low++;
		}
		ans = max(ans, i - low + 1);
	}
	cout <<  ans;
	return 0;
}
