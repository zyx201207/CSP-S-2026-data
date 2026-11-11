#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,i,ans,a[200010],ma,j;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(i=1;i<=n;i++) ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2){
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				ma=max(ma,a[i]&a[j]);
		cout<<ma;
		return 0;
	}
	if(m==n){
		ma=a[1];
		for(i=2;i<=n;i++) ma=ma&a[i];
		cout<<ma;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(i=n-1;i>=n-m+1;i--) ans=ans&a[i];
	cout<<ans;
}
