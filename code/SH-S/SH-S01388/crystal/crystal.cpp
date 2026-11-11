#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int s[500010];
bool check(int x){
	int cnt=0x3f3f3f3f3f3f3f3f;
	for(int i=x;i<=n;++i){
		cnt=min(cnt,a[i]*x-(s[i]-s[max(0ll,i-x-1)]));
	}
	//cout<<cnt<<" "<<x<<"\n";
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		//++mp[a[i]];
	}
//	for(int i=1;i<=n;++i){
//		ans=max(ans,mp[a[i]]);
//		//cout<<mp[a[i]]<<" ";
//	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	int l=0;
	int r=n+1;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
