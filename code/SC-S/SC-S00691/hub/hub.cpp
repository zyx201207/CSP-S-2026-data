#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e3+5,inf = 0x3f3f3f3f3f3f3f3f;
int n,k,fa[N],siz[N],dis[N];
bool vis[N],viss[N];
vector<int>g[N];
pair<int,int>cnt[N];
int find(int x){
	if(fa[x]!=x)return fa[x]=find(fa[x]);
	return x;
}
void solve(){
	for(int i=1;i<=n;i++)g[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		cnt[i]={u,v};
	}
	int ans=inf;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++)fa[j]=j,siz[j]=1,vis[j]=viss[j]=0,dis[j]=inf;
		int sum=0;
		for(int j=1;j<=n;j++)if((1<<j-1)&i){
			vis[j]=1;
			++sum;
		}
		if(sum!=k)continue;
		for(int j=1;j<n;j++)if(vis[cnt[j].first]&&vis[cnt[j].second]){
			int u=cnt[j].first,v=cnt[j].second;
			u=find(u),v=find(v);
			if(u==v)continue;
			if(siz[u]>siz[v])swap(u,v);
			siz[v]+=siz[u],fa[u]=v;
		}
		sum=0;
		for(int j=1;j<=n;j++)if(vis[j]&&viss[find(j)]==0){
			viss[find(j)]=1,++sum;
		}
		if(sum>2)continue;
		queue<int>q;
		for(int j=1;j<=n;j++)if(vis[j]){
			dis[j]=0;
			q.push(j);
		} 
		while(q.size()){
			int u=q.front();
			q.pop();
			vis[u]=1;
			for(int v:g[u]){
				dis[v]=min(dis[v],dis[u]+1);
				if(!vis[v])q.push(v);
			}
		}
		int p=0;
		for(int j=1;j<=n;j++)p=max(p,dis[j]);
		ans=min(ans,p);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/