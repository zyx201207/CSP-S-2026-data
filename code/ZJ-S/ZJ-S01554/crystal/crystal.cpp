#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],s[500005],ans;
bool check(int x){
	int minn=LONG_LONG_MAX;
	for(int i=x;i<=n;i++){
		minn=min(minn,a[i]*x-s[i]+s[i-x]);
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
