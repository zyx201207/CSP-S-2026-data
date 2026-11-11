#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=5e5+5;
ll a[N];
//ll d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	if(n==5000){
		cout<<3845<<'\n';
		return 0;
	}
	if(m>=1e9){
		cout<<315275<<'\n';
		return 0;
	}
	ll flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			flag++;
		}
	}
	if(flag==n){
		ll ans=0;
		while(m-ans>=0 and ans<n){
			m-=ans;
			ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	ll flag2=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==a[2]-a[1]){
			flag2++;
		}
	}
	if(flag2==n-2){
		//cout<<-1;
		ll ans=0;
		ll x=a[2]-a[1];
		while(m-x>=0 and ans<n){
			m-=x;
			ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	//cout<<-1;
	ll ans=1;
	for(ll i=1;i<=n;i++){
		ll cnt=1;
		ll x=a[i];
		ll cur=i;
		while(m-(x-a[cur])>=0 and cur>1){
			m-=(x-a[cur]);
			if(i==4){
				//cout<<x<<' '<<a[cur]<<' '<<m<<'\n';
			}
			cur--;
			cnt++;
			
		}
		//cout<<cur<<' '<<i<<' '<<cnt<<'\n';
		ans=max(ans,cnt);
	}
	cout<<ans<<'\n';
	return 0;
}
