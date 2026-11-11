#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=500505;
ll recall,n,m,d,q,zt[N];
ll head[N],to[N<<1],nxt[N<<1],cnt,w[N<<1];
void add(ll u,ll v,ll w_){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
	w[cnt]=w_;
}
ll disn[505][505];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>recall>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>zt[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll v,w;
			cin>>v>>w;
			add(m+i,v,w);
			add(v,m+i,w);
		}
	}
	memset(disn,0x3f,sizeof disn);
	for(int now=1;now<=m;now++){
		for(int i=head[now];i;i=nxt[i]){
			for(int j=head[now];j;j=nxt[j]){
				ll u=to[i],v=to[j];
				u-=m;
				v-=m;
				if(u==v) disn[u][v]=0;
				else{
					disn[u][v]=min(disn[u][v],w[i]+w[j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(disn[i][k]!=0x3f3f3f3f3f3f3f3f&&disn[k][j]!=0x3f3f3f3f3f3f3f3f) disn[i][j]=min(disn[i][j],disn[i][k]+disn[k][j]);
			} 
		}
	}
	for(int i=1;i<=q;i++){
		ll u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(int i=head[u];i;i=nxt[i]){
			for(int j=head[v];j;j=nxt[j]){
				ll tu=to[i],tv=to[j];
				tu-=m;
				tv-=m;
				ans=min(ans,zt[u]+zt[v]+disn[tu][tv]+w[i]+w[j]);
			}
		}
		cout<<ans<<'\n'; 
	}
	return 0;
}

