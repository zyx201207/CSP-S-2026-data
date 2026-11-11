#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500009;
ll n,m,d,a[N],s[N];
void solve1(){
	ll ans=1;
	for(ll i=n;i>=1;i--){
		ll op=0,cnt=1;
		for(ll j=i-1;j>=1;j--){
			if(op+a[i]-a[j]>m)
				break;
			cnt++;
			op=op+a[i]-a[j];
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}
void solve3(){
	ll cnt=n;
	for(ll i=1;i<=n-1;i++){
		if(i*(i+1)*d/2>m){
			cnt=i;
			break;
		}
	}
	cout<<cnt<<endl;
}
void solve4(){
	for(ll i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=n;i>=1;i--){
		ll l,r,mid,op;
		l=1;
		r=i;
		while(l<=r){
			mid=l+(r-l)/2;
			op=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			if(op>m){
				l=mid+1;
			}
			else if(op<m){
				r=mid-1;
			}
			else{
				l=mid;
				break;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool bb=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		solve1();
	}
	else{
		d=a[2]-a[1];
		for(ll i=3;i<=n;i++){
			if(a[i]-a[i-1]!=d){
				bb=0;
				break;
			}
		}
		if(bb==1){
			solve3();
		}
		else{
			solve4();
		}
	}
	return 0;
} 
