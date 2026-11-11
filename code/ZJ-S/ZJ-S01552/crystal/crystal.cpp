#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],ans;
int ok(int len,int End){
	int beg=End-len+1;
	if(sum[End]-sum[beg-1]+m>=len*a[End])return 1;
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,s=1;
		while(l<=r){
			int mid=l+r>>1;
			if(ok(mid,i)){
				s=mid;l=mid+1;
			}
			else r=mid-1;
		}
		ans=max(ans,s);
	}
	cout<<ans<<"\n";
	return 0;
}