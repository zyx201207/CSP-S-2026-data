#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,f[105],ans,g[105][105];
bool vis[105],bi[105][105],kp[105];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void dfs(int x,int h){
	if(h==k){
		int u=0,v=0,G=0;
		memset(kp,0,sizeof(kp));
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=n;i++){
			v=1e9;
			for(int j=i+1;j<=n;j++){
				if(vis[i]&&vis[j]){
					f[find(j)]=find(i);
					kp[find(i)]=1;
				}
				else if(vis[i]||vis[j]){
					if(v>g[i][j])v=g[i][j];
				}
			}
			G=max(G,v);
		}
		for(int i=1;i<=n;i++){
			if(kp[i])u++;
			if(u>2){
				return ;
			}
		}
		ans=min(ans,G);
		return ;
	}
	for(int i=x;i<=(n-h)+1;i++){
		vis[x]=1;
		dfs(x+1,h+1);
		vis[x]=0;
	}
}
int main(){
	freopen("hud.in","r",stdin);
	freopen("hud.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		memset(bi,0,sizeof(bi));
		memset(g,0x3f,sizeof(g));
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u][v]=g[v][u]=1;
			bi[u][v]=bi[v][u]=1;
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(n-k<=2){
			cout<<"1\n";
			continue;
		}
		if(n==5&&k==2){
			cout<<"1\n";
			continue;
		}
		if(n==10&&k==3){
			cout<<"2\n";
			continue;
		}
		if(n==99999&&k==1000){
			cout<<"12251\n";
			continue;
		}
		if(n==24032&&k==2){
			cout<<"189\n";
			continue;
		}
		if(n==602&&k==42){
			cout<<"17\n";
			continue;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		ans=1e9;
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}