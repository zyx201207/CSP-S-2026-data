#include<bits/stdc++.h>
#define ll long long 
#define pii pair<long long,int>
using namespace std;
const int N=5e5+5;
ll INF=0x3f3f3f3f3f3f3f3f;
struct node{
	int to,nxt;
	ll w;
}edge[2*N];
int head[N*2],cnt=1;
void add(int x,int y,ll z){
	edge[cnt].to=y;
	edge[cnt].w=z;
	edge[cnt].nxt=head[x];
	head[x]=cnt++;
}
ll dis[N];
bool vis[N];
vector<ll> v[N];
int c,n,m,d,q,w[N];
void dij(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=(n+1)*m;i++) dis[i]=INF,vis[i]=0;
	dis[s]=0;q.push({0,s});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].to,w=edge[i].w;
			if(vis[y]) continue;
			if(dis[x]+w<dis[y]){
				dis[y]=dis[x]+w,q.push({dis[y],y});
//				cout<<y<<" ";
			}
//			cout<<x<<"->"<<y<<" "<<w<<" "<<dis[y]<<"\n";
//			cout<<x<<"->"<<y<<" "<<dis[y]<<"\n";
		}
	}
//	cout<<"\n\n";
//	cout<<dis[2]<<" ";
	for(int i=1;i<=m;i++){
		v[s].push_back(dis[i]);
	}
//	cout<<v[s][1]<<" ";
//	cout<<"\n\n111111111111111111\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		int x,y,pre;
		scanf("%d%d",&x,&y);
		add(x,m*i+x,y),add(m*i+x,x,y);
//		cout<<x<<" "<<m*i+x<<" "<<y<<"\n";
		pre=x;
		for(int j=2,a,b;j<=k;j++){
			scanf("%d%d",&a,&b);
			add(m*i+pre,m*i+a,0);add(m*i+a,m*i+pre,0);
			add(a,m*i+a,b),add(m*i+a,a,b);
//			cout<<m*i+pre<<" "<<m*i+a<<'\n';
			pre=a;
//			cout<<a<<" "<<m*i+a<<'\n';
		}
	}
//	for(int i=head[12];i;i=edge[i].nxt){
//		cout<<edge[i].to;
//	}
	for(int i=1;i<=m;i++){
		dij(i);
//		for(int j=1;j<=m;j++){
//			cout<<(int)v[i][j]<<" ";
//		}
//		cout<<"\n";
	}
//	cout<<INF<<" ";
//	cout<<v[123][127];
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",v[a][b-1]+w[a]+w[b]);
	}
	return 0;
} 
