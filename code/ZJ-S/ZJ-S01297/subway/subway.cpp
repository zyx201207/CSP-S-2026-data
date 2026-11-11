#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll c,n,m,d,q,w[N],a[510][510];
struct P{
	ll v,w;
};
vector<P> e[N];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(a,0x3f,sizeof a);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
	    ll k,v,t;
	    cin>>k;
	    while(k--){
	    	cin>>v>>t;
	        e[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)e[i].size();j++){
			for(int k=j+1;k<(int)e[i].size();k++){
				ll u=e[i][j].v,v=e[i][k].v,w=e[i][j].w+e[i][k].w;
				a[u][v]=a[v][u]=min(a[u][v],w);
				
			}
		}
	}
	for(int i=1;i<=n;i++) a[i][i]=0;
	floyd();
	while(q--){
		ll ans=0,x=0,y=0;
		cin>>x>>y;
		ans+=w[x];
		ans+=w[y];
		ll mi=0,op=0;
		for(auto i:e[x]){
			for(auto j:e[y]){
				if(op==0){
					op=1;
					mi=a[i.v][j.v]+i.w+j.w;
				}
				else{
					mi=min(mi,a[i.v][j.v]+i.w+j.w);
				}
			}
		}
		cout<<ans+mi<<'\n';
	}
	return 0;
}