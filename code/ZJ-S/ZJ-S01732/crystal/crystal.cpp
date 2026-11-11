#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5 + 10;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int n , m;
bool check(int x){
	for(int i = 1;i < n;i++){
		if(i + x - 2 >= n)continue;
		int tmp = c[i + x - 2] - c[i - 1];
		if(tmp <= m){
			return true;
		}
	}
	return false;
}
signed main (){
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "r" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m; 
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	int l = 1 , r = n;
	for(int i = 1;i < n;i++){
		b[i] = a[i + 1] - a[i];
	}
	memset(c , 0x7f , sizeof(c));
	for(int i = 1;i < n;i++){
		c[i] = c[i - 1] + b[i];
	}
	int ans = 0;
	while(l <= r){
		int mid = (l + r) / 2;
		if(check(mid) == true){
			ans = max(ans , mid);
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
