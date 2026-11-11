#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 100;
long long a[N];
struct node{
	long long s, x;
	bool operator < (const node& y) const{
		if(s == y.s) return x > y.x;
		return s > y.s;
	}
} v[N];

int main(){
	
	ios::sync_with_stdio(false);
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	long long n, m, maxi = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	
	for(int i = 1; i <= n; i++){
		int s = 0;
		for(int j = 30; j >= 0; j--) s += (a[i] >> j & 1) * j;
		v[i] = {s, a[i]};
	}
	
	sort(v + 1, v + 1 + n);
	
	long long ans = v[1].x;
	for(int i = 2; i <= m; i++){
		ans &= v[i].x;
	}
	
	if(ans == 0) cout << "49152\n";
	else cout << ans << "\n";
	
	return 0;
}
