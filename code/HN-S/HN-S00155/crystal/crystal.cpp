#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5e5 + 2;
int n;
ll m, a[N];
ll sum;

inline bool check(int len){
	sum = 0;
	for(int i = 1; i <= len; ++ i){
		sum += a[i];
	}
	if(a[len] * len - sum <= m) return 1;

	for(int r = len + 1; r <= n; ++ r){
		sum = sum - a[r - len] + a[r];
		if(a[r] * len - sum <= m) return 1;
	}
	return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; ++ i){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);

	int l = 2, r = n, mid, ans = 1;
	while(l <= r){
		mid = l + r >> 1;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;

	return 0;
}

/*

g++ crystal.cpp -o crystal -std=c++14 -O2 -Wall
./crystal

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/