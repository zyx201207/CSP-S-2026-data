#include<bits/stdc++.h>
using namespace std;
int a[500005], b[500005];
int ok(){
	int maxm = 0;
	for (int i = 1;i <= 500005;i++){
		if (b[i] > maxm){
			maxm = b[i];
		}
	}
	return maxm;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, maxn = 0;
	long long m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		int x;
		cin >> x;
		b[x]++;
		a[i] = x;
	}
	sort(a + 1, a + n + 1);
	int sum = m;
	int cs = 0;
	while(sum > 0){
		cs++;
		for (int i = cs;i >= 1;i--){
			for (int j = 1;j <= cs;j++){
				sum -= abs(a[cs + 1] - a[j]);
			}
		}
	}
	for (int i = 1;i <= cs;i++){
		a[i] = a[cs + 1];
		b[a[i]]++;
	}
	int ans = ok();
	cout << ans;
	return 0;
}
