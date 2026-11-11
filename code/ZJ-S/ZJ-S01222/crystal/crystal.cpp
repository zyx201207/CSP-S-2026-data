#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
	ll ans=0;
	for(ll i=1,j=1;i<=n;i++){
		while(j+1<=n&&sum[j+1]-sum[i]<=m) j++;
		ans=max(ans,j-i+1);
	}
	cout<<ans;
	return 0;
}
