#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e2+29;
const ll M=5e5+29;
ll c,n,m,d,q,u,v;
ll w[M],k[N],vis[N],ans;
ll t[N][N],f[N][N],bi[N][N];
vector<ll> s[M],g[M],nwg[N];
inline ll read(){
	char x;
	ll sum=0,f=1;
	x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-') f=-1;
		x=getchar();
	}
	while('0'<=x&&x<='9'){
		sum=sum*10+x-'0';
		x=getchar();
	}
	return sum*f;
}
void dfs(ll x,ll sum){
	if(sum>vis[x]) return;
	vis[x]=sum;
	for(ll i=0;i<nwg[x].size();i++){
		ll nx=nwg[x][i];
		dfs(nx,sum+t[x][nx]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(ll i=1;i<=m;i++) w[i]=read();
	for(ll i=1;i<=n;i++){
		k[i]=read();
		for(ll j=1;j<=k[i];j++){
			u=read();
			v=read();
			s[u].push_back(i);
			g[u].push_back(v);
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(ll i=1;i<=m;i++){
		ll top=0,ls[N],ls2[N];
		if(s[i].size()>1){
			for(ll j=0;j<s[i].size();j++){
				top++;
				ls[top]=s[i][j];
				ls2[top]=g[i][j];
			}
		}
		for(ll j=1;j<=top;j++){
			for(ll k=j+1;k<=top;k++){
				ll lsm=ls2[j]+ls2[k],a1=ls[j],a2=ls[k];
				t[a1][a2]=lsm;
				f[a1][a2]=lsm;
				t[a2][a1]=lsm;
				f[a2][a1]=lsm;
				nwg[a1].push_back(a2);
				nwg[a2].push_back(a1);
			}
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			vis[j]=1e18;
		}
		dfs(i,0);
		for(ll j=1;j<=n;j++){
			f[i][j]=vis[j];
		}
	}
	while(q--){
		u=read();
		v=read();
		ans=1e18;
		for(ll i=0;i<s[u].size();i++){
			for(ll j=0;j<s[v].size();j++){
				ll sm=g[u][i]+g[v][j]+f[s[u][i]][s[v][j]];
				ans=min(ans,sm);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
