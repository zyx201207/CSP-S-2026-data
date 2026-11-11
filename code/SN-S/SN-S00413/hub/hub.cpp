#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,v[N],d[N];vector<int>g[N];
void dfs(int x){
	v[x]=0;for(int y:g[x])if(v[y]==1)dfs(y);
} 
void sol(){
	cin>>n>>k;for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;g[u].push_back(v);g[v].push_back(u);
	}
	int ans=n+1;
	for(int S=0;S<(1<<n);S++){
		vector<int>a;for(int j=0;j<n;j++)if((S>>j)&1)a.push_back(j+1),v[j+1]=1;
		if((int)a.size()!=k)continue;
		int cnt=0;for(int x:a)if(v[x])cnt++,dfs(x);
		if(cnt>2)continue;
		for(int i=1;i<=n;i++)d[i]=-1;
		queue<int>q;for(int x:a)q.push(x),d[x]=0;
		int ret=0;
		while(q.size()){
			int x=q.front();q.pop();
			for(int y:g[x])if(d[y]==-1){d[y]=d[x]+1;q.push(y);ret=max(ret,d[y]);}
		}ans=min(ans,ret);
	}cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int c,t;cin>>c>>t;while(t--)sol();
	return 0;
}

