#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
long long n, m, a[N], b[N], sum, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		sum += a[n] - a[i];
	}
	while(sum > m){
		sum -= (n-1) * (a[n] - a[n-1]);
		n--;
	}
	cout << n;
}
