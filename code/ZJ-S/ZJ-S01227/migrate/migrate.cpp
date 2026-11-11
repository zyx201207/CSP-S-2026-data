#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
const ll inf=4e18;
int C,T,n,f[N],g[N],deg[N],ind[N];
ll a[N],d,ans;
vector<int> G[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=0;i<=n;++i){
			G[i].clear(),ind[i]=f[i]=0;
		}
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				if(a[i]-a[j]<=d) G[j].emplace_back(i);
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) f[j]=1e9,g[j]=deg[j]=0;
			for(int j=i;j<=n;++j){
				for(int k:G[j]) deg[k]++;
			}
			f[i]=0,g[i]=1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int u=q.front();q.pop();
//				printf("i=%d u=%d %d\n",i,u,g[u]);
				for(int v:G[u]){
					if(f[v]>f[u]+1){
						f[v]=f[u]+1;
						g[v]=g[u];
					}
					else if(f[v]==f[u]+1){
						g[v]+=g[u];
					}
//					printf("%d->%d %d\n",u,v,deg[v]);
					if(!(--deg[v])) q.push(v);
				}
			}
			for(int j=i;j<=n;++j){
				if(g[j]==2) ans++;
			}
		}
		printf("%d\n",ans);
	}
}