#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
#define ll long long
const ll maxn=5e5+7;
ll a[maxn];
ll sum[maxn],cnt[maxn];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	memset(sum,0,sizeof sum);
	memset(cnt,0,sizeof cnt);
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		cnt[i]=a[i]*i;
	}
//	for(ll i=1;i<=n;i++){
//		cout<<i<<" "<<sum[i]<<" "<<cnt[i]<<endl;
//	}
	ll ans=0;
//	cout<<endl;
	ll f=0;
	for(ll i=2;i<=n;i++){
		if(cnt[i]-sum[i]<=m){
			ans=i;
			if(cnt[i]-sum[i]==m)
				f=i;
//			cout<<i<<" "<<ans<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}

