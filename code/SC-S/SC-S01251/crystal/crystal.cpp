#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n;
long long m, a[N], s[N];
bool check(long long x){
	long long num = 9e18;
	for (int i = x;i <= n;i++)
		num = min(num,a[i]*(x-1)-(s[i-1]-s[i-x]));
	return num <= m;
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) s[i] = s[i-1]+a[i];
	int l = 1, r = n;
	long long ans, mid;
	while(l <= r){
		mid = (l+r)/2;
		if (check(mid)){
			l = mid+1;
			ans = mid;
		}else
			r = mid-1;
	}
	cout << ans;
	return 0;
}