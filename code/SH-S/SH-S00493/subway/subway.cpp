#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+5,M=505;
struct Node{
	int id,val;
	bool operator <(const Node t)const{
		return val>t.val;
	}
};
bool vis[505];
int n,m,dt[M][M],d,q,dis[M][M],w[N];
vector<Node>g[N+M],v[M];
void dijkstra(int st){
//	cout<<"?"<<st<<'\n';
	memset(vis,0,sizeof vis);
	priority_queue<Node>q;
	q.push({st,0});
	while(q.size()){
		int now=q.top().id,val=q.top().val;q.pop();
//		cout<<"?"<<now<<' '<<val<<'\n'; 
		if(vis[now])continue;
		vis[now]=true;
		dt[st][now]=dt[now][st]=val;
		for(auto xx:v[now]){
			int x=xx.id;
			if(!vis[x])
				q.push({x,val+dis[now][x]});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
//	cout<<"1"; 
	memset(dis,0x3f,sizeof dis);
	//cout<<'!';
	int sum=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			g[i+m].push_back({u,v});
			g[u].push_back({i+m,v});
		}
	}
	for(int i=m+1;i<=n+m;i++){
		for(auto xx:g[i]){
			int x=xx.id,t1=xx.val;
			for(auto yy:g[x]){
				int y=yy.id,t2=yy.val;
				dis[y-m][i-m]=min(dis[y-m][i-m],t1+t2);
				dis[i-m][y-m]=min(dis[i-m][y-m],t1+t2);
			//	cout<<y-m<<' '<<i-m<<' '<<dis[y-m][i-m]<<'\n';
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		//cout<<'!';
		for(int j=i+1;j<=n;j++){
			//cout<<i<<' '<<j<<'\n';
			if(i!=j&&dis[i][j]!=dis[0][0]){
				v[i].push_back({j,dis[i][j]});
				v[j].push_back({i,dis[i][j]}); 
		//		cout<<i<<' '<<j<<'\n';
			}
		}
	}
	//cout<<"*";
	for(int i=1;i<=n;i++)dijkstra(i);
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans=dis[0][0];
		for(auto xx:g[l]){
			int x=xx.id-m,t1=xx.val;
			for(auto yy:g[r]){
				int y=yy.id-m,t2=yy.val;
			//	printf("x=%d,y=%d,dt[x][y]=%d\n",x,y,dt[x][y]);
				ans=min(ans,t1+t2+dt[x][y]);
			}
		}
		printf("%d\n",ans+w[l]+w[r]);
	}
	//cout<<":";
	return 0;
}
