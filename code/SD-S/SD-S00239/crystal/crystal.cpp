#include<bits/stdc++.h>
#define dbg(x) cerr<<"In Line "<<__LINE__<<" , "<<#x<<" = "<<x<<'\n';
#define ll long long
using namespace std;
const int N=5e5+5;
const ll INF=1e18;
ll n,m;
ll sum[N],a[N];

int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ll can=a[i],temp=0;
		temp=can*i-sum[i];
		if(temp<=m)ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}

