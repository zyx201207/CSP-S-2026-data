#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[514514],sum[514514],ans,m;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	for(int i=1;i<=n;i++)sum[i]=a[i]+sum[i-1];
	//cout<<endl;
	for(ll l=1,r=1;l<=n,r<=n;l++){
		ll h=0;
		while(r<=n&&l<=n){
			h=(r-l)*a[l]-sum[r]+sum[l];
			if(h>m)break;
			r++;
			//cout<<h<<" "<<l<<" "<<r<<" "<<sum[r]<<" "<<sum[l]<<endl;
		}
		ans=max(r-l,ans);
//		if(r-l==3846){
//			cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<" "<<sum[l]<<" "<<sum[r]<<" "<<sum[r]-sum[l]<<" "<<(r-l)*a[l]<<" "<<m<<endl; 
//		}
	}
	cout<<ans;
	return 0;
}

