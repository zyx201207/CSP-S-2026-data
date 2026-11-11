#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500005], pre[500005];
bool check(int x){
	for(int i = 1; i + x - 1 <= n; i++){
		int sum = pre[i + x - 1] - pre[i - 1];
		if(sum >= a[i + x - 1] * x - m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i];
	} 
	long long l = 0, r = n, ans = 0;
	while(l <= r){
		long long mid = (l + r) >> 1;
		if(check(mid)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << ans;
}
/*
LUOGU UID 1549034

ίχίχίχ 
*/ 
