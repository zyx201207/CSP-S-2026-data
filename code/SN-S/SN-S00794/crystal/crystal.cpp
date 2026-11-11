#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int m , n , f , a[N];
long long num , sum;

int solve(int x) {
	int p = a[x] - a[1];
	int ans = (0 + p) * x / 2;
	return ans;
}

int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	cin >> a[1] >> a[2];
	int w = a[2] - a[1];
	for(int i = 3;i <= n;i++) {
		cin >> a[i];
		if(a[i] - a[i - 1] != w) f = 1;
	}
	if(f == 0) {
		for(int i = 1;i <= n;i++) {
			int t = solve(i);
			if(t < m) sum = i;
		}
		cout << sum;
		return 0;
	}
	return 0;
}

