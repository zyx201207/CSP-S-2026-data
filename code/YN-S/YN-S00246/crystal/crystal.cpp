#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 5e5+5;
long long m;
long long a[N],sum[N];
long long ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out" ,"w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	cnt = 0,ans = 1;
	for(int i = 1;i <= n;i++){
		if(sum[i]+m >= a[i]*i) ans = i;
	}
	cout << ans << '\n';
	return 0;
}
