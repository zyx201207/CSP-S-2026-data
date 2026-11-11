#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500010],d[500010],s[500010],d2[500010],s2[500010];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		d2[i]=d[i]*(i-1);
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+d[i];
		s2[i]=s2[i-1]+d2[i];
	}
	int ans=0,r=1;
	for(int l=1;l<=n;l++){
		while(r<n && s2[r+1]-s2[l]-(l-1)*(s[r+1]-s[l])<=m) r++;
		ans=max(ans,r-l+1);
		//cout<<l<<' '<<r<<endl;
	}
	cout<<ans<<endl;
	return 0;
}


//s2[j]-s2[i]-(i-1)*(s[j]-s[i])