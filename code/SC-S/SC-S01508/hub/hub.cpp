#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=15;
int c,t;
int n,k,fa[N],vis[N],dis[N][N],minn=1e9;
vector<int>edge[N];
void dfs(int x,int fx){
	dis[x][fx]=1;dis[fx][x]=1;
	fa[x]=fx;
	for(auto y:edge[x]){
		if(y==fx)continue;
		dfs(y,x);
	}
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		iota(fa+1,fa+1+n,1);
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e9;
			}
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		dfs(1,0);
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		int u=(1<<n)-1;
		for(int s=0;s<=u;s++){
			int tmp=0,cnt=0;
			for(int i=0;i<n;i++)if((s>>i)&1)cnt++;
			queue<int>q;
			for(int i=0;i<n;i++){
				if((s>>i)&1){
					bool f=0;
					auto h=q;
					while(h.size()){
						int x=h.front();
						h.pop();
						for(auto y:edge[x])if(y==i+1)f=1;
						if(f==1)break;
					}
					if(!f)tmp++;
					q.push(i+1);
				}
			}
			if(tmp>2||cnt!=k)continue;
			int maxn=0;
			for(int i=1;i<=n;i++){
				int ans=1e9;
				for(int j=0;j<n;j++){
					if(!((s>>j)&1))continue;
					ans=min(ans,dis[i][j+1]);
				}	
				if(ans==1e9)ans=0;
				maxn=max(ans,maxn);
			}
//			if(maxn==1)cout<<s<<"\n";
//			cout<<dis[10][7]<<"\n";
			minn=min(minn,maxn);
		}
		cout<<minn<<"\n";
		minn=1e9;
		for(int i=1;i<=n;i++)edge[i].clear();
	}
	return 0;
}