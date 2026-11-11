#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll maxn=1e5+5;
const ll ml=505;

struct edge{
	ll x,to,val;
};
ll c,n,m,d,q; 
ll sta[maxn];
ll dis[maxn],vis[maxn];
vector<edge> g[maxn];
edge es[5*maxn];
edge le[maxn][2];

void dijkstra(ll x,ll y){ 
	ll mx=1e17,tgt=-1;
	for(int i=1;i<=n+m;i++){
		dis[i]=1e18;
		vis[i]=0;
	}
	dis[x]=0;
	for(int j=1;j<=n+m;j++){
		//for(int i=1;i<=n+m;i++) cout<<dis[i]<<" " ;
		for(int i=1;i<=m+n;i++){
			mx=1e18;
			if(dis[i]<mx&&!vis[i]){
				mx=dis[i];
				tgt=i;
				//cout<<i<<endl;
				break;
			}
		}
		vis[tgt]=1; 
		if(vis[y]==1&&dis[y]!=1e18) return;
		for(int i=0;i<g[tgt].size();i++){
			dis[g[tgt][i].to]=min(dis[g[tgt][i].to],dis[tgt]+g[tgt][i].val);
			//cout<<"upup"<<g[tgt][i].to<<endl;
		}
		
    }
    return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	ll cnt=0,flg1=1,flg2=1;
	for(int i=1;i<=n;i++){
		le[i][0]={0,0,0}; 
		le[i][1]={0,0,0};
	}
	for(int i=1;i<=m;i++) cin>>sta[i];
	for(int i=1;i<=n;i++){
		ll tmp;
		cin>>tmp;
		if(tmp!=2) flg1=0;
		for(int j=1;j<=tmp;j++){
			ll zt,val;
			cin>>zt>>val;
			es[++cnt]={i+m,zt,val};
			if(!le[i+m][0].x) le[i+m][0]={0,zt,val};
			else le[i+m][1]={0,zt,val};
		}
	}
	for(int i=1;i<=cnt;i++){
		g[es[i].x].push_back({0,es[i].to,es[i].val});
		g[es[i].to].push_back({0,es[i].x,es[i].val});
	}

	while(q--){
		ll x,y;
		cin>>x>>y;
		dijkstra(x,y);
		//for(int i=1;i<=n+m;i++) cout<<dis[i]<<" " ;
		cout<<dis[y]+sta[x]+sta[y]<<endl;
	}
	return 0;
}
