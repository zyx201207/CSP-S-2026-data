#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005];
inline bool check(int lim){
	int cnt=0;
	for(int i=lim;i;i--){
		cnt+=a[lim]-a[i];
	}
	if(cnt<=m){
		return 1;
	}
	for(int i=lim+1;i<=n;i++){
		cnt-=a[i-1]-a[i-lim];
		cnt+=(a[i]-a[i-1])*(lim-1);
		if(cnt<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

