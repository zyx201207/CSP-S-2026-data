#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
bool flag=1;
bool check(ll num){
	ll res=0;
	for(int i=num;i<=n;i++){
		ll now=a[i];
		for(int j=i-num+1;j<i;j++){
			res+=now-a[j];
		}	
		if(res<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ll p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)p=a[i]-a[i-1];
		else if(i>2){
			if(a[i]-a[i-1]!=p)flag=0;
		}
	}
	if(flag){
		double r=(sqrt(1+4*m))-1;
		r/=2;
		cout<<(ll)r+1;
		return 0;
	}
	sort(a+1,a+n+1);
	ll l=0,r=n;
	ll ans=0;
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
