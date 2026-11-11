#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
const int N=5000+6,M=5e5+6;
vector<int> g[N];
int fa[N];
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}int is[N];
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy)fa[fx]=fy;
}int dis[N];
void dfs(int x,int fa,int dep){
	//cout<<x<<"\n";
	dis[x]=min(dis[x],dep);
	for(int u:g[x]){
		if(u==fa)continue;
		dfs(u,x,dep+1);
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		f(i,1,n)g[i].clear();
		f(i,1,n-1){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}int ans=1e18;
		f(i,0,(1<<n)-1){
			int ct=0;
			f(j,1,n)fa[j]=j,is[j]=0;
			f(j,0,n-1){
				if((i>>j)&1)is[j+1]=1,ct++;		
			}if(ct!=k)continue;
			//cout<<i<<"\n";
			f(j,1,n){
				if(is[j]==0)continue;
				for(int u:g[j]){
					if(is[u]==1){
						merge(j,u);
					}
				}
			}int cnt=0;
			f(j,1,n)if(find(j)==j&&is[j]==1)cnt++;
			//f(j,1,n)cout<<is[j]<<" ";cout<<"\n";
			//cout<<cnt<<"\n";
			//cout<<"? "<<cnt<<"\n";
			f(j,1,n)dis[j]=1e18;
			if(cnt>2)continue;
			f(j,1,n){
				if(is[j]==1)dfs(j,0,0);
			}
			int mx=0;
			f(j,1,n)mx=max(mx,dis[j]);
			ans=min(mx,ans);
		}cout<<ans<<"\n";
	}
	return 0;
}