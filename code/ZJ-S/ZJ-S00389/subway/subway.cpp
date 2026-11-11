#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
struct Node{
	int x,t;
	bool operator<(const Node& A)const{
		return A.t<t;
	}
};
int w[N],t[N][N],a[N][N],dis[N],vis[N],ans,tu[N][N];
vector<int>g[N];
int dist(int x,int y){
	priority_queue<Node>qu;
	qu.push({x,0});
	while(qu.size()){
		Node now=qu.top();qu.pop();
		if(now.x==y){
			return dis[now.x];
		}
		if(vis[now.x])continue;
		vis[now.x]=1;
		for(auto i:g[now.x]){
			if(dis[i]>dis[now.x]+tu[i][now.x]){
				dis[i]=dis[now.x]+tu[i][now.x];
				qu.push({i,dis[now.x]+tu[i][now.x]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)tu[i][j]=INT_MAX;
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int tt;
			scanf("%lld%lld",&a[i][j],&tt);
			t[i][a[i][j]]=tt;
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				if(tu[a[i][j]][a[i][p]]==INT_MAX){
					g[a[i][j]].push_back(a[i][p]);
					g[a[i][p]].push_back(a[i][j]);
				}
				tu[a[i][j]][a[i][p]]=min(tu[a[i][j]][a[i][p]],t[i][a[i][j]]+t[i][a[i][p]]);
				tu[a[i][p]][a[i][j]]=min(tu[a[i][p]][a[i][j]],t[i][a[i][j]]+t[i][a[i][p]]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=m;i++)dis[i]=INT_MAX,vis[i]=0;
		dis[x]=0;
		ans=w[x]+w[y];
		ans+=dist(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}
