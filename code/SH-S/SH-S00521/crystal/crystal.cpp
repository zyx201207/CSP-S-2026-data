#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m;
ll a[N],d[N],s[N],e[N],minn[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll flag=0;
	for(ll i=2;i<n;i++)if(a[i]-a[i-1]!=a[i+1]-a[i]){flag=1;break;}
	if(!flag){
		ll dd=a[2]-a[1];
		float k=8*m/dd;
		ll ans=(-1+sqrt(1+k))/2;ans++;
		if(ans>n)ans=n;
		cout<<ans;
	} 
	else{
		memset(minn,0x7f,sizeof minn);
		for(ll i=1;i<=n;i++)d[i]=a[i]-a[i-1];
		d[1]=0;
		reverse(d+1,d+1+n);
		for(ll i=1;i<=n;i++)s[i]=s[i-1]+d[i];
		for(ll i=1;i<=n;i++){
			ll pre=0;
			for(ll len=1;len+i-1<=n;len++){
				ll cur=pre+s[i+len-1]-s[i-1];
				pre=cur;minn[len]=min(minn[len],cur);
			}
		}
		ll ans=upper_bound(minn+1,minn+1+n,m)-minn;
		cout<<ans;
	}
	return 0;
} 
