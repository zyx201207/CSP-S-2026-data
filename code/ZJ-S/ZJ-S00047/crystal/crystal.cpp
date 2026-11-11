#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll sum[500005];
ll mxlen;
//Find 1~y that true | w*(y-l+1)-(sum[y]-sum[l-1])<=m | the min l
void work(ll y,ll w){
	ll l=1,r=y,ans=y;
	while(l<=r){
		ll mid=(l+r)/2;
		if(w*(y-mid+1)-(sum[y]-sum[mid-1])<=m){
			ans=mid,r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	mxlen=max(mxlen,y-ans+1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//don't forget to delete!!!!!
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=1;i<=n;i++){
		work(i,a[i]);
	}
	cout<<mxlen;
	return 0;
}