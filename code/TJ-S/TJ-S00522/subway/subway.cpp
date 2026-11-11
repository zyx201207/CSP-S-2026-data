#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int c,n,m,d,q;	//m=edge
int w[N];
struct node{
	int begin;
	int end;
	int len;
	int next;
};
node edge[2*N]={};
int h[N]={};
int x=1;
int k;
void add(int b,int e,int len){
	edge[x].begin=b;
	edge[x].end=e;
	edge[x].len=len;
	edge[x].next=h[b];
	h[b]=x;
	x++;
}
int dis[N]={};
bool vis[N]={};
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void init(int start){
	for(int i=1;i<=N;i++){
		dis[i]=INT_MAX;
		vis[i]=0;
	}
	dis[start]=0;
	vis[start]=1;
}
int ne;
void dijkstra(int start){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push({0,start}); 
	for(int i=1;i<=ne;i++){
		int where=pq.top().second;
		int lon=pq.top().first;
		vis[where]=1;
		pq.pop();
		for(int j=h[where];j!=0;j=edge[j].next){
			int end=edge[j].end;
			int len=edge[j].len;
//			cout<<"киЁз"<<where<<"->"<<end<<endl;
			if(vis[end]!=1&&lon+len<dis[end]){
				dis[end]=lon+len;
				pq.push({dis[end],end});
			}
		}
	}
}
bool up[500005]={}; 
int t[505][500005]={};
int zhanting[500005]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	ne=2*m+1;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		int last;
		for(int j=1;j<=ki;j++){
			int y,t;
			cin>>y>>t;
			int ting=y+m;
			if(up[y]==1){
				y=ne;
			}else{
				up[y]=1;
			}
			add(y,ting,t);
			add(ting,y,t);
			if(j==1){
//				cout<<y<<"<->"<<ting<<endl;
				last=y;
				continue;
			}
			add(last,y,0);
			add(y,last,0);
//			cout<<y<<"<->"<<ting<<endl<<last<<"<->"<<y<<endl<<endl;
			last=y;
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;
		cin>>start>>end;
		start+=m;
		end+=m;
		init(start);
		dijkstra(start);
//		cout<<ne<<" ";
//		for(int j=1;j<=ne;j++){
//			cout<<dis[j]<<" ";
//		}
//		cout<<endl<<dis[end]<<endl;
		cout<<dis[end]+w[start-m]+w[end-m]<<endl;
	}
	return 0;
}
