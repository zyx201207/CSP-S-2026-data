#include<bits/stdc++.h>
#define N 200005
#define M 100005
using namespace std;
int c,n,m,d,q,w[N],kk,a[N],t[N],x,y;
int minn[1005][1005];
struct node{
	int to;
	int val;
};

//struct edge{
//	int id;
//	int dis;
//	bool operator< const(edge &xx)const{
//		return dis<xx.dis;
//	}
//};
vector<node> G[M];
//priority_queue<edge> q;
int vis[N],dis[N];
void dfs(int u,int end,int cnt){
	if(u==end){
		dis[u]=min(dis[u],cnt);
		return ;
	}
	for(auto v:G[u]){
		if(vis[v.to]){
			continue;
		}
//		cout<<"u="<<u<<" v="<<v.to<<"\n";
		vis[v.to]=1;
		dfs(v.to,end,cnt+v.val);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
		memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=n;i++){
		cin>>kk;
		for(int j=1;j<=kk;j++){
			cin>>a[j]>>t[j];
			for(int k=1;k<=j;k++){
				if(t[j]+t[k]<minn[a[j]][a[k]]&&t[j]+t[k]<minn[a[k]][a[j]]){
					G[a[j]].push_back({a[k],t[j]+t[k]});
					G[a[k]].push_back({a[j],t[j]+t[k]});
					minn[a[j]][a[k]]=t[j]+t[k];
					minn[a[k]][a[j]]=t[j]+t[k];
				}
				
//		cout<<"u="<<a[j]<<" v="<<a[k]<<"\n";
//		cout<<"u="<<a[k]<<" v="<<a[j]<<"\n";
			}
		}
	}
//	cout<<"\n";
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int ans=w[x]+w[y];
		vis[x]=1;
		dfs(x,y,0);
		cout<<ans+dis[y]<<"\n";
	}
	return 0;
}

