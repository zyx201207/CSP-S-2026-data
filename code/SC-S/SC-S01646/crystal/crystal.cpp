#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n , m , a[N] , b[N] , c = 0 , mn = 1e18;
bool ch(int x){
	for(int i = 1; i <= n - x + 1; i ++){
		if(a[i + x - 1] * x - b[i + x - 1] + b[i - 1] <= m)return 1;
	}return 0;
}signed main(){
	ios::sync_with_stdio(0) , cin.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)cin >> a[i] , mn = min(mn , a[i]);
	for(int i = 1; i <= n; i ++)a[i] -= mn;
	sort(a + 1 , a + n + 1);
	for(int i = 1; i <= n; i ++)b[i] = b[i - 1] + a[i];
	int l = 1 , r = n;
	while(l <= r){
		int m = (l + r) / 2;
		if(ch(m))l = m + 1 , c = m;
		else r = m - 1;
	}cout << c;return 0;
}