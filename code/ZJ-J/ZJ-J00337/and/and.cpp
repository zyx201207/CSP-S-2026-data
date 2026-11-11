#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll ans;
ll a[200010];
ll T[30];
void dfs(ll x,ll cnt,ll sum){
	if(x==n){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(x+1,cnt,sum);
	dfs(x+1,cnt+1,(sum==0?a[cnt+1]:sum&a[cnt+1]));
}
void fj(ll n){
	ll pos=1;
	while(n){
		if(n%2==1){
			T[pos]++;
		}
		pos++;
		n/=2;
	}
}
void jf(ll n){
	ll pos=1;
	while(n){
		if(n%2==1){
			T[pos]--;
		}
		pos++;
		n/=2;
	}
}
ll rp[35];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	rp[0]=1;
	for(ll i=1;i<=21;i++){
		rp[i]=rp[i-1]*2;
	}
	sort(a+1,a+1+n,greater<ll>());
	if(n<=23){
		dfs(1,0,0);
		cout<<ans;
	}else if(m==1){
		cout<<a[1];
	}else if(m==2&&n<=2000){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans;
	}else{
		cout<<a[m];
	}
	return 0;
}   
     