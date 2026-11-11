#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010];
ll b[500010],sum[500010];
bool check(ll x){
	x--;
	ll l=1,r=x;
	ll res=0,mn;
	for(ll i=1;i<=x;i++)res+=i*b[i];
	mn=res;
	while(r<=n){
		r++;
		l++;
		res=res+x*b[r]-b[l-1]+sum[l-1]-sum[r-1];
//		cout<<res<<endl;
		mn=min(mn,res);
	}
	return mn<=m;
}
ll find(ll l,ll r){
	if(l>=r)return check(l)?l:0;
	ll mid=(l+r)/2;
	if(check(mid)){
		ll pos=find(mid+1,r);
		return pos!=0?pos:mid;
	}else return find(l,mid-1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++)b[i]=a[i+1]-a[i];
//	for(int i=1;i<n;i++)cout<<b[i]<<endl;
//	cout<<endl;
	for(ll i=1;i<n;i++)sum[i]=sum[i-1]+b[i];
	cout<<find(1,n);
	return 0;
}