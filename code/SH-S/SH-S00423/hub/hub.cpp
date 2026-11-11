#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MaxN=1e6+5;
int C,T,n,K;
vector <int> G[MaxN];

bool chosed[MaxN];
bool vis[MaxN];
int dis[MaxN];

void dfs1(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(vis[v]==0 and chosed[v]) dfs1(v);
	}
	return ;
} 
void dfs2(int u){
	for(int v:G[u]){
		if(chosed[v]==0 and dis[u]+1<dis[v]){
			dis[v]=dis[u]+1;
			dfs2(v);
		}
	}
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	for(;T;T--){
		cin>>n>>K;
		bool Tepan=(n&1);
		int ans=LONG_LONG_MAX;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			if(i<=(n>>1) and (u!=i or v!=i+1)) Tepan=0;
			if(i>(n>>1) and (u!=i-(n>>1) or v!=i+1)) Tepan=0;
		}
		if(Tepan){
			if(K==n){
				cout<<0<<endl;
				continue;
			}
			n>>=1;
			if(ceil(1.0*K/2.0)>=ceil(1.0*n/2.0)){
				cout<<1<<endl;
				continue;
			}
			else{
				cout<<ceil(1.0*n/2.0)-(ceil(1.0*ceil(1.0*n/2.0)/2.0)+(K>>1)-1)+1<<endl;
			}
		}
		else if(n<=10){
			for(int i=0;i<=(1ll<<n);i++){
				int tmp=0;
				bool flag=0;
				for(int j=0;j<n;j++){
					if((i&(1ll<<j))==(1ll<<j)) tmp++;
				}
				if(tmp!=K) continue;
				for(int j=0;j<n;j++){
					if((i&(1ll<<j))==(1ll<<j)) chosed[j+1]=1;
					else chosed[j+1]=0;
				}
				tmp=0;
				for(int j=1;j<=n;j++) vis[j]=0;
				for(int j=1;j<=n;j++){
					if(chosed[j] and vis[j]==0) dfs1(j),tmp++;
					if(tmp>2){
						flag=1;
						break;
					}
				}
				if(flag) continue;
				for(int j=1;j<=n;j++) dis[j]=LONG_LONG_MAX;
				for(int j=1;j<=n;j++){
					if(chosed[j]) dis[j]=0,dfs2(j);
				}
				int res=0;
				for(int j=1;j<=n;j++){
					if(chosed[j]==0) res=max(res,dis[j]);
				}
				ans=min(ans,res);
				Failed:;
			}
			cout<<ans<<endl;
		}
		else if(n<=1000 and K<=2){
			for(int i=1;i<=n;i++){
				chosed[i]=1;
				for(int j=i+1;j<=n;j++){
					int res=0;
					chosed[j]=1;
					for(int k=0;k<=n;k++) dis[k]=LONG_LONG_MAX;
					dis[i]=0;
					dfs2(i);
					dis[j]=0;
					dfs2(j);
					for(int k=1;k<=n;k++){
						if(chosed[k]==0) res=max(res,dis[k]);
					}
					chosed[j]=0;
					ans=min(ans,res);
				}
				chosed[i]=0;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
