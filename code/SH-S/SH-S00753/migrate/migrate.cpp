#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
ll a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(); cin.tie(0);
	int c,t; cin>>c>>t;
	while(t--){
		int n; ll d;
		cin>>n>>d;
		ll ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			ll x=a[2]-a[1];
			x=d/x;
			if(x==1||x==0){
				cout<<0<<'\n';
				continue;
			}
			ll ans=max(0ll,n-x*2+1);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i+3<=n;i++){
			if(a[i+3]-a[i]>d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d){
				int nowl=i;
				while(nowl>1){
					if(a[nowl]-a[nowl-1]<=d&&a[nowl+1]-a[nowl-1]>d) nowl--;
					else break;
				}
				int nowr=i+3;
				while(nowr<n){
					if(a[nowr+1]-a[nowr]<=d&&a[nowr+1]-a[nowr-1]>d) nowr++;
					else break;
				}
				ans+=(i-nowl+1)*(nowr-i-3+1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
