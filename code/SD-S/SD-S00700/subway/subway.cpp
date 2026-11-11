#include<iostream>
#include<vector>
#include<queue>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[601000],k[601000],tot=0,head[601000];
struct opp{
	int v,nt,w;
}a[1001000];
void add(int u,int v,int w){
//	cout<<tot;
	a[++tot].v=v;
	a[tot].w=w;
	a[tot].nt=head[u];
	head[u]=tot;
}
priority_queue<pair<int,int> >pq;
bool vis[601000];
int dis[601000];
int dijistra(int s,int e){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=m+n;i++){
		vis[i]=0;
		dis[i]=1e18;
//		cout<<dis[i]<<endl;
	}
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty()){
		int x=pq.top().second;
//		cout<<x<<endl;
		pq.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=a[i].nt){
			int y=a[i].v;
//			cout<<x<<" "<<y<<" "<<dis[y]<<endl;
			if(dis[y]>dis[x]+a[i].w){
				dis[y]=dis[x]+a[i].w;
				pq.push({-dis[y],y});
//				cout<<x<<" "<<y<<" "<<dis[y]<<endl;
			}
		}
	}
	return dis[e];
}
int dat[510][510];
void sub(){
	for(int s=1;s<=m;s++){
		int k=dijistra(s,0);
		for(int e=1;e<=m;e++){
			dat[s][e]=dis[e];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dat[x][y]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	a.push_back({0,0,0});
	cin>>c>>n>>m>>d>>q;
//	cout<<tot;
	bool A=1;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2)A=0;
//		cout<<i<<" "<<k[i]<<endl;
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
//			cout<<i<<" "<<k[i]<<" "<<j<<endl;
//			cout<<x<<" "<<i+m<<endl;
			add(x,i+m,t);
			add(i+m,x,t);
		} 
	}
	if(A){
		sub();
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dijistra(x,y)<<endl;
//		for(int i=1;i<=n+m;i++)cout<<x<<" "<<i<<" "<<dis[i]<<endl;
	}
} //fc subway4.ans subway.out
