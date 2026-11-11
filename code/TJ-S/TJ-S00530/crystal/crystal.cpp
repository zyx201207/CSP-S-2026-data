#include<bits/stdc++.h>
using namespace std;
//asd
//Hope AC
typedef long long ll;
ll n,m,a[500005],ans=-1;
bool check(ll mid){
	ll x=a[mid],sum=m,qans=0;
	for(ll i=mid;i>=1;i--){
		if(a[i]>x)break;
		sum=sum-(x-a[i]);
		if(sum<0){
			if(qans>ans)ans=qans;
			return 0;	
		}
		qans++;
	}
	return 1;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)/2;
//		cout<<"mid="<<mid<<"\n";
		if(check(mid)){
			l=mid+1;
//			cout<<"T,+l+,l="<<l<<",r="<<r<<"\n";
			if(mid>ans)ans=mid;
		}else{
			
			r=mid-1; 
//			cout<<"F,-r-,l="<<l<<",r="<<r<<"\n";
		}
	}
	ll asdf=ans;
	for(ll i=ans+1;i<=n;i++){
		if(a[i]>a[ans])break;
		asdf++;
	}
	cout<<asdf;
	//asd
	//Wei Da De Yang Yang
	//tj-s00530
	return 0;
}
