#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct Node{
	int v,w;
	bool operator<(const Node&T)const{
		return w>T.w;
	}
};
int c,n,m,d,q,t[505][N],dis[N],w[N];
bool vis[N],A[505][N];
vector<Node>a[505];
int dijkstra(int s,int S,int T){
	int ans=0,pos=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof vis);
	dis[s]=0;
	ans+=w[S]+w[T];
	ans+=t[s][S];
	priority_queue<Node>q;
	q.push({s,0});
	while(!q.empty()){
		Node x=q.top();
		q.pop();
		if(A[x.v][T]){
			pos=x.v;
			ans+=t[x.v][T];
			break;
		}
		if(vis[x.v])continue;
		vis[x.v]=1;
		for(int i=0;i<a[x.v].size();i++){
			Node u=a[x.v][i];
			if(A[u.v][T]&&dis[x.v]+u.w<=dis[u.v]){
				dis[u.v]=dis[x.v]+u.w; 
				q.push({u.v,dis[u.v]});
			}
		}
	}
	return dis[pos]+ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x>>t[i][j];
			A[i][x]=1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(A[j][i]&&A[k][i]&&k!=j){
					a[j].push_back({k,t[j][i]+t[k][i]});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,t,ma=0;
		cin>>s>>t;
		for(int j=1;j<=n;j++){
			if(A[j][s]){
				ma=max(ma,dijkstra(j,s,t));
			}
		}
		cout<<ma<<endl;
	}
	return 0;
}
