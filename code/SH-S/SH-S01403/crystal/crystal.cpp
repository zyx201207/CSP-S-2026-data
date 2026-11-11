#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int maxn = 5e5 + 5;
i64 n, m, negative;
///negative : position of lats negative
i64 a[maxn], pre[maxn], negpre[maxn];
bool check(int aim){
	for(int r = aim; r <= n; r++){
		int l = r - aim + 1;
		i64 time;
		//set l to r to a[r]
		if(negative < l){
			//all positive
			time = a[r] * aim - (pre[r] - pre[l - 1]);
		}
		else if(l <= negative < r){
			//r is positive
			time = a[r] * aim - pre[r] + (negpre[negative] - negpre[l - 1]);
		}
		else{
			//all negative
			time = negpre[r] - negpre[l - 1] - abs(a[r] * aim);
		}
		if(time <= m) return true;
	}
	return false;
}
int bs(){
	int l, r, mid, ans;
	l = 1;
	r = n;
	ans = 0;
	while(l <= r){
		mid = (l + r) / 2;
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] < 0){
			negpre[i] = negpre[i - 1] + abs(a[i]);
			negative = i;
		}
		else pre[i] = pre[i - 1] + a[i];
	}
	cout << bs();
	return 0;
}
