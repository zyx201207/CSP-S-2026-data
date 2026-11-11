#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
ll a[500005];
ll sum[500005];
int n;
ll m;
bool check(int x){
	ll num=1e18;
	for(int i=1;i<=n-x+1;i++){
		ll ss=0;
		ll sss=0;
		for(int j=i;j<=i+x-1;j++){
			ss+=a[j]-a[i];
			//sum[j]=sum[j-1]+a[j];
		}
		sss=sum[i+x-1]-sum[i-1]-a[i]*x;
		//cout<<sss-ss<<"\n";
		num=min(num,sss);
		//cout<<num<<"\n";
	}
	return num<=m;
}
signed main(){
	memset(sum,0,sizeof(sum));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<"\n";
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n,mid,ans=-1;
	while(l<=r){
		mid=l+(r-l)/2;
		//cout<<mid<<"\n\n";
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
