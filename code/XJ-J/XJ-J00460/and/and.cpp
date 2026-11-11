#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false),cin.tie(0);
#define int long long
using namespace std;
int a[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	fast;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	cout << a[n-m-1];
	return 0;
}