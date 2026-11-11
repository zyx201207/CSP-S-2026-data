#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],pr[500005],ans,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
	for(ll i=1,j=1;i<=n;i++){
		while((a[j]*(j-i+1)-pr[j]+pr[i-1]<=m)&&j<=n) j++;
		ans=max(ans,j-i);
	}
	cout<<ans;
	return 0;
} 
