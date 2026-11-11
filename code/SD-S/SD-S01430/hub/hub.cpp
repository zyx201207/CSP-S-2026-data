#include<bits/stdc++.h>
using namespace std;
const int MAXN=10005;
const int INF=0x3f3f3f3f;
vector<int> g[MAXN];
int fa[MAXN],dis[MAXN],in[MAXN];
bool vis[MAXN];
void dijikstra(int s){
	memset(vis,false,sizeof(vis));
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dis[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto e=pq.top();
		pq.pop();
		int u=e.second;
		if(vis[u]){
			continue;
		}
		for(auto edge:g[u]){
			int v=edge;
			int w=1;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int find(int x){
	if(fa[x]!=x){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void uni(int a,int b){
	int x=find(a);
	int y=find(b);
	if(x!=y){
		fa[x]=y;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			in[v]++;
			in[u]++;
		}
		memset(dis,0x3f,sizeof(dis));
		dijikstra(1);
		int L=1;
		int R=n;
		vector<int> ans;
		int mid=(L+R)/2;
		int last=0;
		for(int i=1;i<=n;i++){
			if(in[i]==1){
				continue;
			}
			if(find(mid)!=find(last)&&dis[i]>dis[mid]){
				dis[mid]=0;
				uni(last,mid);
				last=mid;
				k--;
				dijikstra(mid);
			}
			int maxx=INT_MIN;
			for(int i=1;i<=n;i++){
				if(dis[i]!=0){
					maxx=max(maxx,dis[i]);
					ans.push_back(maxx);
				}
			}
		}
		int minn=INT_MAX;
		for(auto v:ans){
			minn=min(minn,v);
		}
		cout<<minn<<endl;
	}
	return 0;
}/*0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10*/
/*0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9*/
