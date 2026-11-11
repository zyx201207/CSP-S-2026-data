#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v;
	long long w;
};
int c,n,m,d,q;
int k[501]={0};
int cnt[501]={0};
int w[500001]={0};
//int sub[500001][21]={0};
int a[501][50001]={0};
int t[501][50001]={0};
vector<edge> g[50001];
bool vis[50001]={false};
vector<int> sub[50001];
long long dis[50001]={0};
long long dijkstra(int st,int ed){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
	q.push({0,st});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		for(edge e:g[u]){
			long long w=e.w;
			int v=e.v;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return dis[ed];
}
void slove1(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				g[a[i][j]].push_back({a[i][l],t[i][j]+t[i][l]});
			}
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		cout<<dijkstra(st,ed)+w[st]+w[ed]<<'\n';
	}
}
void slove2(){
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			//cnt[a[i][j]]++;
			//sub[cnt[a[i][j]]]=
			sub[a[i][j]].push_back(i);
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	//if(c<=11){
		slove1();
	//}
	//if(c>=12 && c<=19){
		//slove2();
	//}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
