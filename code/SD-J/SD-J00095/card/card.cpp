#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=3e5+5;
ll n,m,a[N],q[N],_[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		memset(q,0,sizeof q);
		ll sz=0;
		for(ll j=i;j<=n;j++){
			ll k=a[j];
			bool p=false;
			ll l;
			for(l=1;l<=sz;l++)if(q[l]==k){p=true;break;}
			ll tsz=sz;
			if(p){for(ll r=l;r<=tsz;r++){q[r]=0;if(sz!=0)sz--;}}
			q[++sz]=k;
		}
		for(ll j=1;j<=sz;j++)_[q[j]]++;
	}
	for(ll i=1;i<=m;i++)cout<<_[i]<<' ';
	return 0;
}
