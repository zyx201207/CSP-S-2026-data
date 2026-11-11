#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],n,m;
ll check_AB(){
	ll d=a[2]-a[1];
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]!=d) return 0; 
	}
	return d;
}
ll cost(ll sum,ll len,ll x){
	return x*(len-1)-sum;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	ll d=check_AB();
	if(d){
		ll l=1,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if((mid-1)*a[1]+(mid-2)*(mid-1)*d/2<=m) l=mid+1;
			else r=mid-1;
		}
		cout<<r;
		return 0;
	}//13-18 30point
	ll l=1,r=1,ans=1,sum=a[1];
	while(r!=n){
		ans=max(r-l+1,ans);
		int len=r-l+1;
		while(cost(sum,len+1,a[r+1])>m){
			sum-=a[l],l++;
			len=r-l+1;
		}
		r++,sum+=a[r];
	}
	ans=max(l-r+1,ans);
	cout<<ans;//1-9 45point
	return 0;
}
//WC you shou shi zhi shang de  ba you li kai le 
//zhi nen yi zhi shou da zi le 
//mei sin si zuo ti le
//si nao kuai xiang a
//tong tong tong 
//te shu xin zhi dou A bu liao wo yao fei le 
//hao tong 
