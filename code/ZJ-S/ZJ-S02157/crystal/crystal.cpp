#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll inf=1e13;
ll a[500010];
ll solve(){
	ll ans=1,cnt=0,L=1,mx=1;
	for(int i=2;i<=n;i++){
		ll h=a[i]-a[i-1];
		cnt+=h*(i-L);
		ans++;
		while(cnt>m&&L<i){
			cnt-=a[i]-a[L];
			ans--;
			L++;
		}
		mx=max(mx,ans);
	}
	return mx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<solve()<<'\n';
	return 0;
}
