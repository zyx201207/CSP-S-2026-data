#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
bool check(int mid){
	int sum=0,minn=9e18;
	for(int i=1;i<=mid;i++) sum+=a[i];
	minn=min(minn,a[mid]*mid-sum);
	for(int i=mid+1;i<=n;i++){
		sum-=a[i-mid];
		sum+=a[i];
		minn=min(minn,a[i]*mid-sum);
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
