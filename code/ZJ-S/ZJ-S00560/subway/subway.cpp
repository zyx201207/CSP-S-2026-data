#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int M=2e4+5,N=505;
int C,n,m,d,q;
int w[N];
int a[M],t[N][M],k[N];
struct node{
	int v,id;
};
vector<node>g[M];
bool vis[N];
int dis[N];
struct edge{
	int w,u,id;
	bool operator <(const edge& others)const{
		return others.w<w;
	}
};
void dijkstra(int st,int ed){
	
	priority_queue<edge,vector<edge>>q;
	int ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)dis[j]=1e18,vis[j]=0;
		if(!t[i][st])continue;
		while(!q.empty())q.pop();
		q.push({t[i][st],st,i});
		dis[st]=0;
		while(!q.empty()){
			edge it=q.top();
			q.pop();
			int u=it.u,ds=it.w,nowid=it.id;
			if(u==ed){
				ans=min(ds+t[nowid][u]+w[ed]+w[st],ans);
				break;
			}
			if(vis[u])continue;
			vis[u]=1;
			for(auto it1:g[u]){
				int v=it1.v,newid=it1.id;
				bool flag=0;
				if(newid!=nowid||v==ed)flag=1;
				if(!flag){
					for(auto it2:g[v]){
						if(it2.id!=nowid){
							flag=1;
							break;
						}
					}
				}
				if(!flag)continue;
				int w=0;
				if(newid!=nowid){
					w=t[nowid][u]+t[newid][u];
				}
				if(dis[v]>ds+w){
					dis[v]=ds+w;
					q.push({dis[v],v,newid});
				}
			}
		}
	}
	cout<<ans<<"\n";
	
}
void solve(){
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,T;j<=k[i];j++){
			cin>>a[j]>>T;
			t[i][a[j]]=T;
		}
		/*
		如何考虑t数组的使用
		需要开一个
		T[i][j]表示第i条铁路，标号为j的地铁站到地铁口的时间
		a数组可以开成1维 
		*/
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				g[a[j]].push_back({a[l],i});
				g[a[l]].push_back({a[j],i});
			}
		}
		/*
		现在我们已经知道了图
		跑的时候要判断是否切换了地铁
		也就是当id与原本的id不同时则称切换了id
		当前的w+=t[原id][u]+t[现id][u]
		哪些点是要走的呢？
		首先是同铁路中有终点，或是这个点是个换乘点，
		其次就是换乘 
		*/
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<":";
//		for(int j=0;j<g[i].size();j++)cout<<g[i][j].v<<" "<<g[i][j].id<<";"<<" ";
//		cout<<"\n";
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dijkstra(u,v);
	}
}

signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	system("fc subway.out subway4.ans");
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
/*
24pts



地铁线路是500 地铁站数是5e5 每个站最多被20条铁路覆盖

先考虑最暴力的方法

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
2 3

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
