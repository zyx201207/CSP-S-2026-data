#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
ll n,m;
ll a[N],t[N];
ll tot[N];
ll ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(ll i=1;i<=n;++i) cin>>a[i];
	for(ll i=1;i<=n;++i){
		memset(tot,0,sizeof(tot));
		for(ll j=1;j<=n;++j){
			t[j]=a[j];
		}
		ll desk=0;
		for(ll k=i;k<=n;++k){
			if(!tot[t[k]]){
				t[++desk]=t[k];
				++tot[t[k]];
			}else{
				for(ll j=1;j<=desk;++j){
					if(t[j]==t[k]){
						for(;j<=desk;++j){
							--tot[t[j]];
							t[j]=0;
						}
					}
				}
				t[++desk]=t[k]; 
			}
		}
		for(ll j=1;j<=desk;++j)
			++ans[t[j]];
	}
	for(ll i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}

