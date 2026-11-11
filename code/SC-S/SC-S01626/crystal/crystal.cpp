#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],need[N],start,ans;
ll con(ll mid,ll d){
//	cout<<(need[d]-need[mid])-mid*(a[d]-a[mid])<<" ";
	return (need[d]-need[mid])-mid*(a[d]-a[mid]);
}
ll f(ll l,ll r,ll d){
	while(l<=r){
		int mid=(l+r)/2;
		if(con(mid,d)>m){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(ll i=2;i<=n;i++){
		need[i]=need[i-1]+(i-1)*(a[i]-a[i-1]);
	}
//	for(ll i=1;i<=n;i++){
//		cout<<need[i]<<" ";
//	}
	for(ll i=1;i<=n;i++){
		if(need[i]<=m){
			ans=i;
		}else{
			start=i;
			break;
		}
	}
//	cout<<"\n";
	for(ll i=start;i<=n;i++){
		ll line=f(1,i-1,i);
//		cout<<line<<" ";
		ans=max(ans,i-line+1);
	}
	cout<<ans;
	return 0;
} 