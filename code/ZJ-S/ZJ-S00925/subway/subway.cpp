#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N=5e5+5;
struct node{
	int from;
	int to;
	long long dis;
	
	bool operator <(const node &other) const{
		return dis>other.dis;
	} 
};
struct ques{
	int x,y;
	int ind;
	long long ans;
}qu[100005];
priority_queue<node> q;
vector<node> e[3*N];
int n,m,c,d,qt;
int w;
int k;
long long a,aa;
long long t;
long long dist[N*3];
bool vis[N*3];
int tot=0;

void Dijkstra(int s){
	memset(vis,0,sizeof(vis));
	memset(dist,0x7f,sizeof(dist));
	
	node cur;
	dist[s]=0;
	vis[s]=1;
	for(auto ed:e[s]) q.push(ed);
	while(!q.empty()){
		//cout<<q.size()<<"size\n";
		cur=q.top();
		q.pop();
		long long u=cur.from,v=cur.to,w=cur.dis;
		//cout<<dist[u]<<' '<<dist[v]<<' '<<w<<'\n';
		if(dist[v]>dist[u]+w){
			dist[v]=dist[u]+w;
			if(!vis[v]){
				for(auto ed:e[v]){
					if(vis[ed.to]) continue;
					q.push(ed);
				}
				vis[v]=1;
			}	
		}
	}
}


bool cmp1(ques qq1,ques qq2){
	if(qq1.x==qq2.x) return qq1.y<qq2.y;
	return qq1.x<qq2.x;
}
bool cmp2(ques qq1,ques qq2){
	return qq1.ind<qq2.ind;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>qt;
	tot=m;
	for(int i=1;i<=m;i++){
		cin>>w;
		tot+=1;
		e[i].push_back({i,tot,w});
		e[tot].push_back({tot,i,w});
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		tot++;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			e[a+m].push_back({a+m,tot,t});
			e[tot].push_back({tot,a+m,t});
		}
	}
	for(int i=1;i<=qt;i++){
		int l,r;
		cin>>l>>r;
		qu[i].x=min(l,r);
		qu[i].y=max(l,r);
		qu[i].ind=i;
	}
//	for(int i=1;i<=tot;i++){
//		for(auto ed:e[i]){
//			cout<<ed.from<<' '<<ed.to<<' '<<ed.dis<<'\n';
//		}	
//		cout<<'\n';
//	}
	
	sort(qu+1,qu+1+qt,cmp1);
	for(int i=1;i<=qt;i++){
		if(i==1) Dijkstra(qu[i].x);
		else if(qu[i].x!=qu[i-1].x) Dijkstra(qu[i].x);
		qu[i].ans=dist[qu[i].y];
	}
	sort(qu+1,qu+1+qt,cmp2);
	for(int i=1;i<=qt;i++){
		cout<<qu[i].ans<<'\n';
	}
	
	return 0;
}