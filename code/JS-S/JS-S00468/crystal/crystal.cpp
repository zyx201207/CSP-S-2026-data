#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;

ll a[N],sum[N];
ll m,n;
ll cnt=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
for(ll i=1;i<=n;i++){
	sum[i]=sum[i-1]+a[i];
}
	///sort(sum+1,sum+n+1);
	ll l=0;
	ll dis=0;
	for(ll i=1;i<=n;i++){
		if(n-i<=cnt)break;
		for(ll j=i;j<=n;j++){
			dis=((j-i)*a[j])-(sum[j-1]-sum[i-1]);
			if(dis>m)break;
			l=j-i+1;
		}
		cnt=max(cnt,l);
		}
	cout<<cnt;
	return 0;
}
