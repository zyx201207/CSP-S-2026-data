#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5;
ll c,n,m,d,q;
ll mp[5005],op[25],tim;
ll w[N];
ll fl[55][55];
ll G[505][505];
ll tota,totb;
ll qa[N],qb[N],ARIS[N],KEI[N];
ll head[N],vis[N],ver[N<<1],nt[N<<1],li[N<<1],tot;
void add(ll u,ll v,ll w){
	nt[++tot]=head[u];
	li[tot]=w;
	ver[tot]=v;
	head[u]=tot;
	return ;
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	memset(head,-1,sizeof(head)); 
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			add(a,i,t);
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			G[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		G[i][i]=0;
	}
	for(ll i=0;i<=50;i++){
		for(ll j=0;j<=50;j++){
			fl[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(ll i=1;i<=m;i++){
		tim=0;
		for(ll j=head[i];~j;j=nt[j]){
			ll v=ver[j];
			if(!mp[v]){
				mp[v]=++tim;
				op[tim]=v;
			}
			fl[0][mp[v]]=fl[mp[v]][0]=min(li[j],fl[mp[v]][0]);
		}
		for(ll a=0;a<=tim;a++){
			for(ll b=0;b<=tim;b++){
				if(!fl[a][b]){
					fl[a][b]=0x3f3f3f3f3f3f3f3f;
				}
			}
			fl[a][a]=0;
		}
		for(ll a=0;a<=tim;a++){
			for(ll b=0;b<=tim;b++){
				if(fl[a][0]+fl[0][b]<fl[a][b]){
					fl[a][b]=fl[a][0]+fl[0][b];
				}
			}
		}
		for(ll a=1;a<=tim;a++){
			for(ll b=1;b<=tim;b++){
				G[op[a]][op[b]]=G[op[b]][op[a]]=min(fl[a][b],G[op[a]][op[b]]);
			}
		}
		for(ll a=0;a<=tim;a++){
			mp[op[a]]=0;
			for(ll b=0;b<=tim;b++){
				fl[a][b]=0x3f3f3f3f3f3f3f3f;
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	while(q--){
		ll x,y,ans=0x3f3f3f3f3f3f3f3f;
		tota=totb=0;
		cin>>x>>y;
		for(ll i=head[x];~i;i=nt[i]){
			ll v=ver[i];
			qa[++tota]=v;
			ARIS[tota]=li[i];
		}
		for(ll i=head[y];~i;i=nt[i]){
			ll v=ver[i];
			qb[++totb]=v;
			KEI[totb]=li[i];
		}
		for(ll i=1;i<=tota;i++){
			for(ll j=1;j<=totb;j++){
				ans=min(ans,ARIS[i]+KEI[j]+G[qa[i]][qb[j]]);
			}
		}
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}/*
再见了，王女 
*/
