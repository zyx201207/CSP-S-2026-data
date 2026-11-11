//15:30
#include <bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;
ll rd(){char c=getchar();ll x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();return x*f;}
ll a[500005],e[505][505],h[500005];
struct ee{ll p,w,nxt;}in[500005];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ll T=rd(),n=rd(),m=rd(),d=rd(),q=rd(),Z=0;
	F(i,1,m)a[i]=rd();
	F(i,1,n){ll k=rd(),x;F(j,1,k)x=rd(),in[++Z]={i,rd(),h[x]},h[x]=Z;}
	memset(e,0x3f,sizeof e);F(i,1,n)e[i][i]=0;
	F(i,1,m)for(ll x=h[i];x;x=in[x].nxt)for(ll y=x;y;y=in[y].nxt)
		e[in[x].p][in[y].p]=e[in[y].p][in[x].p]=min(e[in[x].p][in[y].p],in[x].w+in[y].w);
	F(k,1,n)F(i,1,n)F(j,1,n)e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		ll f=1e18,u=rd(),v=rd();
		for(ll x=h[u];x;x=in[x].nxt)for(ll y=h[v];y;y=in[y].nxt)
			f=min(f,e[in[x].p][in[y].p]+in[x].w+in[y].w);
		printf("%lld\n",f+a[u]+a[v]);
	}return 0;
}
