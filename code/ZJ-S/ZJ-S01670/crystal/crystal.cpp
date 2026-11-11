#include <bits/stdc++.h>
#define syc nb666
#define endl '\n'
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,l,r,mid,ans;
ll ar[N],br[N],cnt,x;
//bool check(ll k){
//	ll need=0;
//	for(ll i=1;i<=k;i++){
//		need=need+ar[k]-ar[i];
//		if(need>m) return false;
//	}
//	return true;
//}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
//	l=1,r=n;
//	while(l<=r){
//		ll mid=(l+r)>>1;
//		if(check(mid)) ans=max(ans,mid),l=mid+1;
//		else r=mid-1;
//	}
	l=1,r=1,x=ar[l];
	while(r<=n && l<=n){
		while((ar[r+1]-x)*(r-l+1)+cnt<=m && r<=n){
			cnt=cnt+(ar[r+1]-x)*(r-l+1);
			x=ar[r+1];
			r++;
		}
	//	cout<<l<<' '<<r<<' '<<x<<' '<<cnt<<endl;
		if(r==n) break;
		ll k=(ar[r+1]-x)*(r-l+1)+cnt;
		//cout<<k<<endl;
		ans=max(ans,(r-l+1));
		while(k>m){
			k=k-(ar[r+1]-ar[l]);
			l++;
		//	cout<<k<<endl;
		}ans=max(ans,(r-l+1));
		cnt=k,x=ar[r+1];
		r=r+1;
	}
	cout<<ans<<endl;
	return 0;
}