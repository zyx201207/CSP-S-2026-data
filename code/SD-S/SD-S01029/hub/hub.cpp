#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,ans,fa[1000007],d[1000007],lca[4007][4007];
vector<int> to[4007];
void dfs(int u,int p){
	fa[u]=p;
	d[u]=d[p]+1;
	for(int v : to[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}
int gtlca(int x,int y){
	if(x==y){
		return x;
	}
	if(lca[x][y]){
		return lca[x][y];
	}
	if(d[x]<d[y]){
		swap(x,y);
	}
	if(d[x]>d[y]){
		return lca[x][y]=lca[y][x]=gtlca(fa[x],y);
	}
	return lca[x][y]=lca[y][x]=gtlca(fa[x],fa[y]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			to[i].clear();
		}
		for(int i=1;i<n;++i){
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		ans=1919810;
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(k>=(n>>1)){
			cout<<1<<'\n';
			continue;
		}
		if(c==13||c==14){
			for(int i=0;i+k-2<=(n>>1);++i){
				int kkk=(n>>1)+2-k-i;
				ans=min(ans,max((i>>1)+(i&1)+1,(kkk&1)+(kkk>>1)));
			}
			cout<<ans<<'\n';
			continue;
		}
		if(k==2){
			d[0]=0;
			dfs(1,0);
			memset(lca,0,sizeof(lca));
			for(int i=1;i<=n;++i){
				lca[i][i]=i;
			}
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					gtlca(i,j);
				}
			}
			for(int i=1;i<=n;++i){
				for(int j=i+1;j<=n;++j){
					int abcd=0;
					for(int k=1;k<=n;++k){
						abcd=max(abcd,min(d[i]+d[k]-(d[lca[i][k]]<<1),d[j]+d[k]-(d[lca[j][k]]<<1)));
					}
					ans=min(ans,abcd);
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<2<<'\n';
	}
	return 0;//ίχ 
}//
