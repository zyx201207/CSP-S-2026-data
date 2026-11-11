#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
struct edge{
	int dis,to,next;
}
e[N];
int c,n,m,d,Q,head[N],dis[N],cnt=1;
bool vis[N];
void add(int u,int v,int d){
	e[cnt].dis=d;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
struct node{
	int dis;
	int pos;
	bool operator<(const &x)const{
		return x.dis<dis; 
	}
};
priority_queue<node> q;
void dijkstra(int s){
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		node tmp=q.top();
		int d=tmp.dis;
		int x=tmp.pos;
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(int i=head[x];i;i=e[i].to){
			int y=e[i].next;
			if(dis[x]+e[i].dis<dis[y]){
				dis[y]=dis[x]+e[i].dis;
			}
			if(!vis[y]){
				q.push({dis[y],y});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	cin>>c>>n>>m>>d>>Q;
	
}
