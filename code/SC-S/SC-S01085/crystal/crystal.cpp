#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005],delta[500005];
ll qzh[500005];
bool check(ll x){
	x--;
	ll sum=0;
	for(ll i=x;i<=n;i++){
		for(ll j=i-x;j<i;j++){
			sum+=qzh[i]-qzh[j];
		}
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)delta[i]=(i<n?a[i+1]-a[i]:0); //a_i要升至a_i+1的代价
	for(ll i=1;i<=n;i++)qzh[i]=qzh[i-1]+delta[i];
	
	bool f=1;
	for(ll i=2;i<=n;i++){
		if(a[i]-a[i-1]!=a[2]-a[1])f=0;
	}
	if(f&&n>1){//B
		ll d=a[2]-a[1];
		ll sum=0,i;
		for(i=1;sum<=m;i++)
			sum+=i*d;
		if(sum>m)i--;
		cout<<min(i,n);
		return 0;
	}
	
	// 45pts
	ll l=1,r=n,ans=0; //能否在小于m次操作的情况下实现用mid个水晶合成大水晶
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
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