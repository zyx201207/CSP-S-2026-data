#include <iostream>
#include <cstdio>
#include <algorithm>

#include <queue>
#include <map>
using namespace std;

int n,m,d,q;
int w[500050]={0};
int head[500550]={0},vis[500550]={0};
int cnt=0;

struct edge{
	public:
		int dse;
		int next;
		int to;
}eg[500550];

struct node{
	public:
		int pt;
		int dsn;
		
		friend bool operator < (node x,node y){
			if(x.dsn<y.dsn){
				return true;
			}
			return false;
		}
};

priority_queue<node> qu;
map<int,map<int,long long>> dis;

void addeg(int u,int v,int wd){
	cnt++;
	eg[cnt].to=v;
	eg[cnt].dse=wd;
	eg[cnt].next=head[u];
	head[u]=cnt;
	
	return ;
}

void dijkstra(int s){
	dis[s][s]=0;
	qu.push(node{s,0});
	
	while(!qu.empty()){
		node cur=qu.top();
		qu.pop();
		int u=cur.pt;
		if(vis[u]){
			continue;
		}
		
		vis[u]=1;
		
		for(int i=head[u];i;i=eg[i].next){
			int v=eg[i].to;
			if(vis[v]){
				continue;
			}
			
			if(dis[s][v]>dis[s][u]+eg[i].dse){
				dis[s][v]=dis[s][u]+eg[i].dse; 
				qu.push(node{v,dis[s][v]});
			}
		}
		
	}
	
	return ;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c;
	cin>>c>>n>>m>>d>>q;
	
	if(c<=6){
		
		for(int i=1;i<=m+n*2;i++){
			for(int j=1;j<=m+n*2;j++){
				dis[i][j]=4e17;
			}
		}
		
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int ax,tx;
				cin>>ax>>tx;
				addeg(m+i,ax,tx);
				addeg(ax,m+i,tx);
			}
		}
		
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<endl; 
		}
		
	}
	
	if(c>=7&&c<=11){
		
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				dis[i][j]=4e17;
			}
		}
		
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int ax1,tx1,ax2,tx2;
			cin>>ax1>>tx1>>ax2>>tx2;
			addeg(ax1,ax2,tx1+tx2);
			addeg(ax2,ax1,tx1+tx2);
		}
		
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<endl; 
		}
		
	}
	
	if(c>=12&&c<=19){
		
		for(int i=1;i<=m+n*2;i++){
			for(int j=1;j<=m+n*2;j++){
				dis[i][j]=4e17;
			}
		}
		
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int ax,tx;
				cin>>ax>>tx;
				addeg(m+i,ax,tx);
				addeg(ax,m+i,tx);
			}
		}
		
		for(int i=1;i<=n;i++){
			dijkstra(i);
		}
		
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<dis[x][y]+w[x]+w[y]<<endl; 
		}
		
	}
	
	
	
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}