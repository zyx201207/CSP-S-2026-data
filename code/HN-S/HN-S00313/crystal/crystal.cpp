#include <bits/stdc++.h>
#define int long long
using namespace std;
int n , m;
int a[500005];
int ans[500005];
bool check(int x){
	for(int j = x ; j <= n ; j ++){
		int i = j - x;
		if(a[j] * x - ans[j] + ans[i]<= m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i ++) ans[i] = ans[i - 1] + a[i];
	int l = 1 , r = n;
	while(l <= r){
		int mid = l + ((r - l) >> 1);
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << r << "\n";
	return 0;
}
