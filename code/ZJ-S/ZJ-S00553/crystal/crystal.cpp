#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=5e5+5;
ll n,m,a[N],d,ans=0;
void dfs(ll x,ll cnt,ll mx,ll arr[]){
	if(x==n){
		ll aaa=0;
		for(ll i=1;i<=cnt;++i){
			aaa+=mx-a[i];
		}
		if(aaa<=m){
			ans=max(ans,cnt);
		}
		return;
	}
	arr[cnt+1]=a[x];
	dfs(x+1,cnt+1,max(mx,a[x]),arr);
	arr[cnt+1]=0;
	dfs(x+1,cnt,mx,arr);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	d=a[2]-a[1];
	bool flag=true;
	for(ll i=3;i<=n;++i){
		if(d!=a[i]-a[i-1]){
			flag=false;
			break;
		}
	}
	if(flag){
		for(ll i=1;i<=n;++i){
			ll a1,an,c,ans;
			a1=d;
			c=i-1;
			an=a1+(c-1)*d;
			ans=(a1+an)*c/2;
			if(ans>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
	}
	else if(n<=5){
		ll arr[6];
		dfs(1,0,LLONG_MIN,arr);
		cout<<ans;
	}
	return 0;
}

