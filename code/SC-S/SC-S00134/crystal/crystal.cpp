#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=500005;
ll n,m,a[M];
ll prx[M];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		prx[i]=prx[i-1]+a[i];
	}
	ll ans=0;
	ll l=1,r=1;
	while(r<=n){
		ll dif=prx[r]-prx[l-1];
		ll len=r-l+1;
		if(a[r]*len-dif>m){
			l++;
		}
		else{
			ans=max(ans,len);
			r++;
		}
		//cout<<l<<" "<<r<<" "<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}