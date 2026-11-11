#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],ans,cnt,s[N],ss[N];
map<ll,ll>mp;
bool check(ll x){
	for(int i=1;i+x-1<=n;i++){
		ll sum=s[i+x-1]-(i-1)*a[i+x-1]+ss[i-1];
		if(sum<=m&&!mp[m-sum]&&(m-sum)%x==0){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ss[i]=ss[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1; 
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
