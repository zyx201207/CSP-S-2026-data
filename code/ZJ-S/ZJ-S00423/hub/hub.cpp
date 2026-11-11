#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vp vector<pii>
using namespace std;
constexpr int N=2000000+10,inf=0x3f3f3f3f3f3f3f3f;
int c,T,n,k;
vi G[N];
namespace sub1{
	bool vis[N],vs[N];
	int fa[N];
	inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	inline void merge(int x,int y){
		if((x=find(x))==(y=find(y))) return;
		fa[x]=y;
	}
	int dis[N];
	inline int bfs(int s){
		for(int i=1;i<=n;i++) dis[i]=inf;
		queue<int> q; q.push(s); dis[s]=0;
		while(!q.empty()){
			int x=q.front(); q.pop();
			if(vis[x]) return dis[x];
			for(int y:G[x]){
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
		}
		return inf;
	}
	inline void solve(){
		int ans=inf;
		for(int i=0;i<(1<<n);i++){
//			cout<<i<<"\n";
			if(__builtin_popcount(i)!=k) continue;
			for(int j=1;j<=n;j++) vis[j]=0,fa[j]=j;
			for(int j=0;j<n;j++) if((i>>j)&1) vis[j+1]=1;
			for(int j=1;j<=n;j++) if(vis[j]){
				for(int k:G[j]) if(vis[k]) merge(j,k);
			}
			int cnt=0;
			for(int j=1;j<=n;j++) vs[j]=0;
			for(int j=1;j<=n;j++) if(vis[j]) cnt+=!vs[find(j)],vs[find(j)]=1;
			if(cnt>2) continue;
//			cout<<"dududu"<<endl;
//			for(int j=1;j<=n;j++) cout<<vis[j]<<" ";cout<<"\n";
			int res=0;
			for(int j=1;j<=n;j++) res=max(res,bfs(j));
			ans=min(ans,res);
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if(c<=3) sub1::solve();
	}
	return 0;
} 
/*
0 2
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
9 10
*/
