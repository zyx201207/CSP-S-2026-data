#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TIE ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N=5e5+5;
ll n,m;
ll a[N];
ll sum[N];
ll tot[N];
ll ans=1;
ll pf,pff=1;

int check(int l,int r){
	ll L=((l-1)*a[r])-tot[l-1];
	ll R=sum[r];
	if(R-L<=m) return 1;
	
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	TIE;
	
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		ll t=a[i]-a[i-1];
		sum[i]=sum[i-1]+t*(i-1);
		tot[i]=tot[i-1]+a[i];
		
	}
	
	for(int i=2;i<=n;i++){
		ll l=1,r=i;
		ll maxx=1;
		int id;
		if(sum[i]<=m){
			ans=max(ans,1ll*i);
			continue;
		}
		while(l<r){
			ll mid=(l+r+1)>>1;
			if(check(mid,i)){
				r=mid-1;
				if(maxx<=i-mid+1){
					maxx=i-mid+1;
					id=mid;
				}
			}
			else{
				l=mid;
			}
		}
		ans=max(ans,maxx);
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
