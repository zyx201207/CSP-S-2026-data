//brown or yellow question,and it runs for O(n log V), costs memory less than 4MB
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];
ll f[200005];
ll ans=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll p=0;
	while((1<<p)<a[n]) p++;
	for(ll i=p;i>=0;i--){
		ll o=0;
		for(ll j=1;j<=n;j++){
			if(f[j]==0&&(a[j]&(1<<i))>0)o++;
		}
		if(o<m) continue;
		ans+=(1<<i);
		for(ll j=1;j<=n;j++){
			if(f[j]==0&&(a[j]&(1<<i))==0) f[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
