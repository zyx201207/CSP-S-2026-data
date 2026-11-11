#include <bits/stdc++.h>
#define int long long
#define N 500050
using namespace std;
int n, m;
int a[N], sum[N];
int work(int l, int r){
	return (r - l + 1) * a[r] - (sum[r] - sum[l - 1]);
}
bool check(int len){
	for(int i = 1, j = len;j <= n;i ++,j ++){
		if(work(i, j) <= m) return 1;
	}
	return 0;
}
int search(){
	int l = 0, r = n, mid;
	while(l < r){
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	return l;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i ++) sum[i] = a[i] + sum[i - 1];
	cout << search();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
