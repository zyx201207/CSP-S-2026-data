#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000010];
int st[21][1000010],l2[1000010],dep[1000010];
void dfs(int u,int fa){
	st[0][u]=fa;
	dep[u]=dep[fa]+1;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int lc[1010][1010],g[1010][1010];
void lca(int u,int v){
	int uu=u,vv=v;
	if(dep[v]>dep[u])swap(u,v);
	while(dep[u]>dep[v]){
		for(int i=20;i>=0;i--){
			if(dep[st[i][u]]>=dep[v])u=st[i][u];
		}
	}
	if(u==v){
		lc[uu][vv]=lc[vv][uu]=u;
		return;
	}
	for(int i=20;i>=0;i--){
		if(st[i][u]!=st[i][v]){
			u=st[i][u],v=st[i][v];
		}
	}
	lc[uu][vv]=lc[vv][uu]=st[0][u];
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	for(int i=1;i<=1000000;i++)l2[i]=l2[i>>1]+1;
//	dep[0]=1;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		dfs(1,0);
		for(int j=1;j<=20;j++){
			for(int i=1;i<=n;i++)st[j][i]=st[j-1][st[j-1][i]];
		}
		if(c>3){
			int ans=0x3f3f3f3f;
			for(int i=1;i<=n;i++){
//				for(int j=i+1;j<=n;j++){
					ans=min(ans,dep[i]);
//				}
			}
			cout<<ans/2<<endl;
		}else{
			for(int i=1;i<=n;i++){
				for(int j:g[i]){
					g[i][j]=1;
				}
			}
			int ans=0x3f3f3f3f,res1=0,res2;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++)lca(i,j);
			}
			for(int i=1;i<(1<<n);i++){
				res1=0x3f3f3f3f,res2=0;
				if(__builtin_popcount(i)!=k)continue;
				int kk=k;
				
				for(int j=1;j<=n;j++){
					if((i>>(j-1))&1)continue;
					for(int k=1;k<=n;k++){
						if(!((i>>(k-1))&1))continue;
//						cout<<j<<'%'<<k<<endl;
						
						res1=min(res1,dep[j]+dep[k]-dep[lc[j][k]]*2);
					}
					res2=max(res2,res1);
				}
				ans=min(ans,res2);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

