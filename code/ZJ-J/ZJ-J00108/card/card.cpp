#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500010];
ll ans[500010];
ll r[500010];
int main(){
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		r[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		ll j=i;
		while(j<=n){
			ans[a[j]]++;
			j=r[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
