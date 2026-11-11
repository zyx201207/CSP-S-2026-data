#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10,P=998244353;
vector<int>g[N];
int ans=1e18,n,k,dis[N],vis[N],f[N],cnt;
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
inline int join(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) f[x]=y,cnt--;
}
void dfs(int p,int s){
	if(p>n){
		if(s!=k) return;
		queue<int>q;
		cnt=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			dis[i]=1e18,f[i]=i;
			if(vis[i]){
				q.push(i),dis[i]=0,cnt++;
				for(auto v:g[i]){
					if(v<i&&vis[v]) join(i,v);
				}
			}
		}
		if(cnt>2) return;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
		}
		for(int i=1;i<=n;i++)
			sum=max(sum,dis[i]);
		ans=min(ans,sum);
		return;
	}
	if(s<k) vis[p]=1,dfs(p+1,s+1);
	vis[p]=0,dfs(p+1,s);
}
void slove(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=1e18,dfs(1,0);
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++) g[i].clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) slove();
	return 0;
}
//CSP-S2026 rp++
//15pts 17:08
//total 263pts
/*
今年再怎样也必须一等；中心目标自然就是七级勾。
争取做T1，T2，然后T3，T4拿高分暴力罢。

现在6:14，感觉没什么可以再挣的分了。
感觉今年WC线得上300啊
*/
