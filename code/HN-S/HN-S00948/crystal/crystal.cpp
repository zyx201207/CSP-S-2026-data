#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int b=0;
	for (int i=1;i<=n;i++){
		b=a[i];
		int cnt=1,as=m;
		for (int j=i-1;j>=1;j--){
			if (b-a[j]>m) continue;
			if (as<b-a[j]) break;
			as-=(b-a[j]);
			cnt++;
		}
		ans=max(cnt,ans);
		as=0;
	}
	cout<<ans;
	return 0;
}
