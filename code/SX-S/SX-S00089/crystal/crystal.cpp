#include <bits/stdc++.h>
using namespace std;
int n, ans;
long long m;
double sum;
long long a[500005];
long long s[500005];

//ding yue tong AK CSp s 2026,能过一等
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	/*for(int i=1;i<=n;i++){
		cin>>a[i];
		cha[i]=a[i]-a[i-1];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	int zj=sum/n;*/
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//s[i]=s[i]+s[i-1];

	}
	int cha = a[2] - a[1];
	ans = m / cha + 1;
	cout << ans;
	return 0;
}