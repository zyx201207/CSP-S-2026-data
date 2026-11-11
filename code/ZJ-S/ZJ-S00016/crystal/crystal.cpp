#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N = 5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int ans = 1,l = 1;
	for(int i = 2;i <= n;i++){
		m -= (a[i]-a[i-1]) * (i-l);
		while(m < 0 && l <= i) m += (a[i]-a[l++]);
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}