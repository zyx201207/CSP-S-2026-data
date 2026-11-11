#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],sum[N];
bool cmp(int a,int b){
	return a<b;
}
bool chk(int x){
	//cout<<x<<'\n';
	int ans=2e18;
	for(int i=x;i<=n;i++){
		ans=min(ans,abs(a[i]*x-(sum[i]-sum[i-x])));
		//cout<<ans<<' ';
	}
	//cout<<'\n';
	if(ans<=m)return 1;
	return 0;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	//for(int i=1;i<=n;i++)cout<<sum[i]<<' ';
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	} 
	cout<<ans;
	return 0;
}

