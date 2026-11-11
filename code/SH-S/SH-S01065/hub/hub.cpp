#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N=1000006;
ll c,T,n,k;
vector<ll> to[N];
ll h[N],mxh[N],g[N];
void dfsokBF(ll u,ll fa,ll o){
	mxh[u]=h[u];
	for(ll v:to[u])if(v!=fa){
		h[v]=h[u]+1;
		dfsokBF(v,u,o);
		mxh[u]=max(mxh[u],mxh[v]);
	}
	if(mxh[u]-h[u]>=o)g[u]=1;
}
bool okBF(ll rtu,ll rtv,ll o){
	for(ll i=0;i<=n;++i)h[i]=mxh[i]=g[i]=0;
	dfsokBF(rtu,0,o);
	dfsokBF(rtv,0,o);
	g[rtu]=1;
	g[rtv]=1;
	ll num=0;
	for(ll i=1;i<=n;++i)num+=g[i];
	return (num<=k);
}
bool iffind=0;
ll b[N],topb=0;
void dfsfind(ll u,ll fa,ll x){
	if(iffind)return;
	b[++topb]=u;
	if(u==x){
		iffind=1;
		return;
	}
	for(ll v:to[u])if(v!=fa){
		dfsfind(v,u,x);
		if(iffind)return;
	}
	topb--;
}
void delE(ll u,ll v){
	for(ll i=to[u].size()-1;i>=0;--i){
		if(to[u][i]==v){
			swap(to[u][i],to[u][to[u].size()-1]);
			to[u].pop_back();
			break;
		}
	}
	for(ll i=to[v].size()-1;i>=0;--i){
		if(to[v][i]==u){
			swap(to[v][i],to[v][to[v].size()-1]);
			to[v].pop_back();
			break;
		}
	}
}
bool OKBF(ll o){
	for(ll i=1;i<n;++i){
		for(ll j=n;j>=i+1;--j){
			iffind=0;
			topb=0;
			dfsfind(i,0,j);
			ll u,v;
			for(ll ib=1;ib<topb;++ib){
				u=b[ib];
				v=b[ib+1];
				delE(u,v);
				if(okBF(i,j,o)){
					to[u].push_back(v);
					to[v].push_back(u);
					return 1;
				}
				to[u].push_back(v);
				to[v].push_back(u);
			}
		}
	}
	return 0;
}
void dfsk21(ll u,ll fa){
	mxh[u]=h[u];
	for(ll v:to[u])if(v!=fa){
		h[v]=h[u]+1;
		dfsk21(v,u);
		mxh[u]=max(mxh[u],mxh[v]);
	}
}
bool ifokk2=0;
void dfsokk2(ll u,ll fa){
	if(ifokk2)return;
	for(ll v:to[u])if(v!=fa){
		dfsokk2(v,u);
	}
}
bool OKk2(ll o){
	for(ll i=1;i<=n;++i){
		h[i]=0;
		for(ll j=1;j<=n;++j)mxh[j]=g[j]=0;
		dfsk21(i,0);
		ifokk2=0;
		dfsokk2(i,0);
		if(ifokk2)return 1;
	}
	return 0;
}
bool OKsol(ll o){
	return OKBF(o);
}
bool OK(ll o){
	if(1<=c&&c<=6&&n<=100)return OKBF(o);
	else return OKsol(o);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		ll u,v;
		for(ll i=1;i<=n-1;++i){
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		ll le=0,ri=n-1,ans=n;
		while(le<=ri){
			ll mid=(le+ri)>>1;
			if(OK(mid)){
				ans=mid;
				ri=mid-1;
			}
			else{
				le=mid+1;
			}
		}
		cout<<ans<<"\n";
		for(ll i=1;i<=n;++i){
			to[i].clear();
		}
	}
	return 0;
}
