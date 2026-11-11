#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll a[N],b[N];
ll use[N];
ll pre[N];
ll n,m;
bool check(ll mid){
	ll minn=0;
	mid--;
	for(ll i=1;i<=mid;i++){
		minn+=(i*b[i]);
	}
	ll prenm=minn;
	for(ll i=mid+1,j=1;i<n;i++,j++){
		prenm=prenm-(pre[i-1]-pre[j-1])+b[i]*mid;
		minn=min(minn,prenm);
	}
	if(minn>m)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		pre[i]=pre[i-1]+b[i];
	}
	ll num=1,ans=1;
	for(ll i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			ans=max(ans,num);
			num=1;
		}
		else{
			num++;
		}
	}
	ans=max(ans,num);
	ll l=1,r=n;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=max(ans,mid);
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
