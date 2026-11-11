#include <bits/stdc++.h>
#define ll long long
#define F(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;
ll rd(){char c=getchar();ll x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();return x*f;}
ll n,m,f[1000005],g[1000005],now,pr[1000005],su[1000005],mxd[1000005],mid;
vector<ll> e[1000005];
ll get(ll u,ll fa){
	mxd[u]=0;
	for(ll v:e[u])if(v!=fa)get(v,u),mxd[u]=max(mxd[u],mxd[v]+1);
}
ll dfs(ll u,ll fa,ll ou){
	ll x=0;for(ll v:e[u])if(v!=fa)pr[v]=x,x=max(x,mxd[v]);
	x=0,reverse(e[u].begin(),e[u].end());
	for(ll v:e[u])if(v!=fa)su[v]=x,x=max(x,mxd[v]);
	reverse(e[u].begin(),e[u].end());
	f[u]=1;
	for(ll v:e[u])if(v!=fa){
		dfs(v,u,max(ou,max(pr[v],su[v]))+1);
		if(mxd[v]>=mid)f[u]+=f[v];
	}
	if(ou<=mid)now=min(now,f[u]);
}
ll uu[1000005],vv[1000005];
bool chk(){
	ll ans=1e9;
	/*F(i,1,n)for(ll v:e[i])if(v>i)*/
	F(I,2,n){
		ll i=uu[I],v=vv[I];
		get(i,v),now=1e9,dfs(i,v,0);ll x=now;
		get(v,i),now=1e9,dfs(v,i,0),ans=min(ans,x+now);
	}
//	cout<<"chk "<<mid<<' '<<ans<<"\n";
	return ans<=m;
}
void sov(){
	n=rd(),m=rd();F(i,1,n)e[i].clear();
	F(i,2,n){ll u=rd(),v=rd();uu[i]=u,vv[i]=v,e[u].push_back(v),e[v].push_back(u);}
	ll l=0,r=n-1,f=r;
	while(l<=r){mid=l+r>>1;if(chk())f=mid,r=mid-1;else l=mid+1;}
	printf("%lld\n",f);
}
int main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ll n=rd(),t=rd();F(i,1,t)sov();return 0;
}
