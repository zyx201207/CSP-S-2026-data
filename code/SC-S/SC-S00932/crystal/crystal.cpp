#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
using ll=long long;
ll n,m;
ll a[N],sum[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
//	ll minn=1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		minn=min(minn,a[i]);
	}
//	if(minn<0)
//		for(int i=1;i<=n;i++) a[i]+=-minn,cout<<"AI: "<<a[i]<<'\n';
	sort(a+1,a+1+n);
	ll ans=1;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
//		cout<<"I: "<<i<<' '<<"SUM: "<<sum[i]<<'\n';
		if(sum[i-1]>=0 && sum[i]<0) break;
		if(sum[i]<=m){
			ans=i;
		}
		else break;
	}
	
	cout<<ans<<'\n';
	return 0;
}