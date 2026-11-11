#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define int long long
const int maxn = 5e5 + 5;
int n, m, a[maxn];
int sum = 0, nw = 0, ans = 0;
int q[maxn], head = 1, tail = 0;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for(int i = 1; i <= n; i++){
		sum += a[i], nw = a[i]; 
		q[++tail] = i;
		int dlt = nw * (tail - head + 1) - sum;
		while(head <= tail && dlt > m){
			sum -= a[q[head]], dlt -= (a[i] - a[q[head]]);
			head++;
		}
		ans = max(ans, tail - head + 1);
		
//		printf("sum:%lld, ans:%lld, nw:%lld, dlt:%lld, head:%lld, tail:%lld\n", sum, ans, nw, dlt, head, tail);
	}
	
	cout << ans << '\n';
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
