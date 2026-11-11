#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],nd[N];
bool cmp(ll a,ll b){
	return a<b;
}inline ll cnt(ll l,ll r){
	return nd[r]-nd[l]-(l-1)*(a[r]-a[l]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	nd[1]=0; 
	for(int i=2;i<=n;++i){
		nd[i]=nd[i-1]+(i-1)*(a[i]-a[i-1]);
	}ll l=1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(nd[mid]<m)l=mid+1;
		else r=mid-1;
	}ll idx=l;
	ll i=n,ans=-1;
	while(i>=idx){
//		if(cnt(j,i)>m){
//			i--;
//			j=i-1;
//			continue;
//		}else{
//			ans=max(ans,i-j+1);
//			j--;
//		}
		ll l=1,r=i-1,mid=0;
		while(l<r){
			mid=l+(r-l)/2;
		//	cout<<l<<' '<<mid<<' '<<r<<endl;
			if(cnt(mid,i)<m)r=mid;
			else l=mid+1;
		}//cout<<l<<' '<<mid<<' '<<r<<endl;
		ans=max(ans,i-mid+1);
	//	cout<<ans<<endl;
		i--;
	}
	cout<<ans;
	return 0;
} 
