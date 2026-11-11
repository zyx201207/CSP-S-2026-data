#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N];
bool check(int len){
	if(len == 1)return true;
	int sum = 0;
	for(int i = 1; i <= len; i++)sum += a[i];
	for(int i = 1; i <= n - len + 1; i++){
		int cnt = a[i + len - 1] * len - sum;
		if(cnt <= m)return true;
		sum = sum - a[i] + a[i + len];
	}
	return false;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = n + 1;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid))l = mid + 1;
		else r = mid;
	}
	cout << l - 1 << endl;
	return 0;
}