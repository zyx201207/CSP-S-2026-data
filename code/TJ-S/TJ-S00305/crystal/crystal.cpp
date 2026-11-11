#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;

int n, ans = 1;
long long m, a[N], pre[N];

bool check(int x, int v){
	int L = v - x + 1, R = v;
	long long Sum = pre[R] - pre[L - 1];
	long long U = a[v] * 1ll * (R - L + 1);
	//cout << v << ":" << x << " " << L << " " << R << " " << Sum << " " << U << "\n"; 
	if(U - Sum > m)return true;
	ans = max(ans, x);
	return false;
}

int main(){
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	for(int i = 1 ; i <= n; i++)pre[i] = pre[i - 1] + a[i];
	
	for(int i = 1; i <= n; i++){
		int l = 1, r = i, mid = 0;
		while(l < r){
			mid = l + (r - l) / 2;
			if(check(mid, i))r = mid;
			else l = mid + 1;
		}
		check(l, i);
		//cout << i << " " << ans << "\n";
	}
	
	cout << ans;
	
	return 0;
} 

/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
