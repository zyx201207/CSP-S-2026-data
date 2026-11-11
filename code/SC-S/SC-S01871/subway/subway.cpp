#include<bits/stdc++.h>
#define pii pair<long long,int>
#define fi first
#define se second
using namespace std;
const int N=5e3+100;
long long w[N],dis[N][N];
vector<pii > g[N]; 
priority_queue<pii,vector<pii>,greater<pii> > q;
void djst(int x){
	dis[x][x]=0;q.push(make_pair(0,x));
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		for(auto c:g[u]){
			int v=c.se,w=c.fi;
			if(dis[x][u]+w<dis[x][v]){
				dis[x][v]=dis[x][u]+w;
				q.push(make_pair(dis[x][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,v;cin>>x>>v;
			g[x].push_back(make_pair(v,i+m));
			g[i+m].push_back(make_pair(v,x));
		}
	} 
	for(int i=1;i<=m;i++) djst(i);
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=w[x]+w[y];
		ans+=dis[x][y];
		cout<<ans<<"\n";
	}
	return 0;
} 