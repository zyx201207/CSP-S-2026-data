#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,ans=1;
int a[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i] = sum[i-1] + a[i];
	}
	for (int i=1;i<n;i++){
		for (int j=i+1;j<=n;j++){
			c = (j-1)*a[j] - sum[j-1] + sum[i-1];
			if(c>m) break;
			ans = max(j-i+1,ans);
		}
	}
	cout << ans<<"\n";
}