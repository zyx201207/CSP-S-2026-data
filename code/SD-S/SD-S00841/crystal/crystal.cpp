#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
#define ll long long
ll n,m,a[N];
ll H,s[N];//最大值    从i到n所有宝石全部合并至少需要的mx 
ll ans=-1;
ll how(ll l,ll r){
	ll ans=0;
	ans+=s[l];
	ans-=s[r+1];
	ans-=(r-l+1)*(H-a[r]);
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	H=a[n];
	a[n+1]=H;
	s[n+1]=0;
	for(ll i=n;i>=1;i--){
		s[i]=s[i+1]+(H-a[i]);
	}
//	for(ll i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			cout<<"how("<<i<<","<<j<<")="<<how(i,j)<<endl;
//		}
//	}
	
	for(ll i=1;i<=n;i++){
//		cout<<"!i="<<i<<endl;
		ll l=i,r=n,mid;
		while(l<r){
			mid=(l+r+1)/2;
//			cout<<l<<" "<<r<<" "<<mid<<" "<<how(i,mid)<<endl;
			if(m>=how(i,mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
//		cout<<"ans="<<ans<<endl;
		ans=max(ans,(l-i+1));
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9




5 8
-3 -1 2 2 7

*/

/*

*/

