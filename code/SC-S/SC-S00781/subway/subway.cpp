#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+9,M=5e2+9,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N],head[N],cnt;
long long dis[M][M],ans,w[N];
struct node{
	int t,v;
};
struct mode{
	int t,lev;
}b[N];
struct kode{
	long long dis,id;
	friend bool operator<(kode x,kode y){
		return x.dis>y.dis;
	}
};
vector <node> e[N];
vector <int> at[N];
vector <node> to[N];
priority_queue <kode> Q;
void dij(int x){
	memset(dis[x],0x3f,sizeof dis[x]);
	dis[x][x]=0;
	Q.push({0,x});
	while(!Q.empty()){
		auto nw=Q.top();Q.pop();
//		cout<<nw.id<<" "; 
		for(auto i:e[nw.id]){
			if(dis[x][i.t]>dis[x][nw.id]+i.v){
				dis[x][i.t]=dis[x][nw.id]+i.v;
				Q.push({dis[x][i.t],i.t});
			}
		}
	}
//	cout<<endl;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];head[i+1]+=k[i]+head[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			b[++cnt]={y,i};
			to[x].push_back({i,y});
			if(!at[x].empty()){
				for(int p:at[x]){
					int nlev=b[p].lev,nt=b[p].t;
					e[nlev].push_back({i,nt+y});
					e[i].push_back({nlev,nt+y});
				}
			}
			at[x].push_back(cnt);
		}
	}
	for(int i=1;i<=n;i++)dij(i);
	for(int i=1;i<=q;i++){
		int x,y;ans=INF;
		cin>>x>>y;
		for(auto f:to[x])for(auto t:to[y])ans=min(ans,dis[f.t][t.t]+w[x]+w[y]+f.v+t.v);
		cout<<ans<<'\n';
	}
	return 0;
}