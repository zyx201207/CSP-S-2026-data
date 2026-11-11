#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+5;

int n, m;
int a[N], ans = 0;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)cin>>a[i];
	sort(a+1, a+n+1);

	int ns = 0;
	for(int i = 1, j = 1; j <= n; j++){
		ns += a[j];
		while(i <= j && (j-i+1)*a[j]-ns > m)ns -= a[i], i++;
		ans = max(ans, j-i+1);
	}
	cout<<ans;
	return 0;
}

