#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],l,r,ans;
bool check(ll x){
	for(ll i=x;i<=n;i++){
		if(a[i]*x-(b[i]-b[i-x])<=m){
			return 1;
		}
	}
	return 0;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	l=1;
	r=n;
	while(l<=r){
		ll mid=(l+r)/2;
//		cout<<mid<<" "<<check(mid)<<"\n";
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
//luogu_liuyuxiaozaizai

