#include<bits/stdc++.h>
#define N 509
#define M 500009
using namespace std;
typedef long long ll;

inline ll read(){
	ll x=0;bool sym=0;char ch=getchar();
	while(!isdigit(ch)) sym^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return sym?-x:x;
}

ll c,n,m,d,q,w[M],ln[N],ti[N];
vector<ll> to[M],wg[M];

inline void input(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		ll k=read();
		for(ll j=1;j<=k;j++){
			ll a=read(),t=read();
			ln[j]=a,ti[j]=t;
		}
		for(ll j=1;j<k;j++)
			for(ll p=j+1;p<=k;p++){
				to[j].push_back(p);
				to[p].push_back(j);
				wg[j].push_back(0);
				wg[p].push_back(0);
			}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	input();
	for(ll i=1;i<=q;i++){
		ll x=read(),y=read();
		
	}

	return 0;
}
