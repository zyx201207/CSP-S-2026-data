#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll> pll;
ll a[10010];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)cnt++;
	}
	if(n-m<cnt){
		cout<<0;
		return 0;
	} 
	if(m==1){
		ll ans=-1e9;
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		ll ans=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll num=a[i]&a[j];
				ans=max(ans,num);
			}
		}
		cout<<ans;
	}else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;
	}else{
		ll maxn=-1e9;
		for(int i=1;i<=n;i++)maxn=max(maxn,a[i]);
		sort(a+1,a+n+1,cmp);
		ll ans=a[1];
		for(int i=2;i<=m;i++)ans=ans&a[i];
		cout<<ans;
	}
	return 0;
}
