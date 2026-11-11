#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=(N+1)*N/2,inf=1e18;
int c,n,m,d,q,w[M],a[N][M],t[N][M],k[N],dist[M];bool flag1=1,flag2=1,vis[M];
vector<vector<pair<int,int>>> g1(M);vector<int> p[M],g2[N];int val[N];
void con1(int k,int i,int j,int x,int y){g1[x].push_back({y,t[k][i]+t[k][j]});g1[y].push_back({x,t[k][i]+t[k][j]});}
void con2(int x,int y){g2[x].push_back(y);g2[y].push_back(x);}
struct node{int id,v;bool operator<(const node other)const{return v>other.v;}};
int dijkstra1(int s,int t){
	for(int i=1;i<=m;i++){dist[i]=inf;}
	for(int i=1;i<=m;i++){vis[i]=0;}
	priority_queue<node> q;dist[s]=0;q.push({s,0});
	while(q.size()){
		int u=q.top().id;q.pop();
		if(vis[u]){continue;}vis[u]=1;
		for(auto v:g1[u]){
			if(dist[v.first]>dist[u]+v.second){
				dist[v.first]=dist[u]+v.second;
				q.push({v.first,dist[v.first]});
			}
		}
	}
	return dist[t];
}
int dijkstra2(int s,int t){
	for(int i=1;i<=n;i++){dist[i]=inf;}
	for(int i=1;i<=n;i++){vis[i]=0;}
	priority_queue<node> q;dist[s]=val[s];q.push({s,val[s]});
	while(q.size()){
		int u=q.top().id;q.pop();
		if(vis[u]){continue;}vis[u]=1;
		for(auto v:g2[u]){
			if(dist[v]>dist[u]+val[v]){
				dist[v]=dist[u]+val[v];
				q.push({v,dist[v]});
			}
		}
	}
	return dist[t];
}
signed main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		cin>>k[i];if(k[i]>2){flag1=0;}
		for(int j=1;j<=k[i];j++){cin>>a[i][j]>>t[i][j];if(j>=2 && t[i][j]!=t[i][j-1]){flag2=0;}}
	}
	if(!flag1 && !flag2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(int k=1;k<=j;k++){con1(i,j,k,a[i][j],a[i][k]);}
			}
		}
		for(int i=1;i<=q;i++){int s,t;cin>>s>>t;cout<<dijkstra1(s,t)+w[s]+w[t]<<endl;}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				for(auto it:p[a[i][j]]){con2(a[i][j],it);}
				p[a[i][j]].push_back(i);
			}
			if(flag1){val[i]=t[i][1]+t[i][2];}else{val[i]=t[i][1]*2ll;}
		}
		for(int i=1;i<=q;i++){
			int s,t,ans=inf;cin>>s>>t;
			for(auto u:p[s]){
				for(auto v:p[t]){
					ans=min(ans,dijkstra2(u,v));
				}
			}
			cout<<ans+w[s]+w[t]<<endl;
		}
	}
	return 0;
}