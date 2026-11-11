#include<bits/stdc++.h>
using namespace std;
struct subw{
	int v,w;
};
int c,n,m,d,q,w[500010],k[510],a[510][510],t[510][510];
map<pair<int,int>,int> mp;
vector<int> zx[500010];
vector<subw> G[510];
bool cache[510],vis[510][510];
int mem[510][510];
void dijia(int u,int st){
	for(auto nxt:G[u]){
		int v=nxt.v,w=nxt.w;
		if(vis[u][v]) continue;
		vis[u][v]=1;
		if(mem[st][v]>mem[st][u]+w){
			mem[st][v]=mem[st][u]+w;
		}
		dijia(v,st);
	}
}
//int bst[510][510];
//void bfs(int s,int e){
//	queue<int> pq;
//	q.push({s,0});
//	while(!q.empty()){
//		int u=pq.front();
//		pq.pop();
//		for(auto nxt:G[u]){
//			int v=nxt.v,w=nxt.w;
//			bst[u][v]=min(bst[u][v],w);
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			zx[a[i][j]].push_back(i);
			mp[{i,a[i][j]}]=j;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:zx[i]){
			for(auto v:zx[i]){
				if(u==v){
					continue;
				}
				G[u].push_back({v,t[u][mp[{u,i}]]+t[v][mp[{v,i}]]});
			}
		}
	}
	while(q-->0){
		int x,y,ans=0;
		cin>>x>>y;
		bool flag=0;
		for(auto s:zx[x]){
			for(auto e:zx[y]){
				if(s==e){
					flag=1;
					ans+=t[s][mp[{s,x}]]+t[e][mp[{e,y}]];
					break;
				}
				memset(vis,0,sizeof(vis));
				dijia(s,s);
				ans=min(ans,mem[s][e]);
			}
			if(flag==1){
				break;
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
		
	}
	
	
	
	return 0;
}
