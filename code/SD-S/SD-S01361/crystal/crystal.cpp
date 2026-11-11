#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
ll n,m,sm,ans,a[N];
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll l=1,r=1;r<=n;r++){
		sm+=(a[r]-a[r-1])*(r-l);
		for(;sm>m;l++)sm-=a[r]-a[l];
		ans=max(ans,r-l+1);
	}cout<<ans;
	return 0;
}
