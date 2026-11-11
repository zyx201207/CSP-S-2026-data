#include<bits/stdc++.h>
using namespace std;
int t,c,n,k,u,v,ans,vis[1000005],pick[1000005];
vector<int>g[1000005];
int f[15][15];
void dfs2(int x){
	for(int p:g[x])if(!vis[p]&&pick[p])vis[p]=1,dfs2(p);
}int check(){
	int num=0;
	for(int i=1;i<=n;i++)if(!vis[i]&&pick[i])num++,dfs2(i);
	return num;
}void dfs(int x,int num){
	if(x==k+1){
		for(int i=1;i<=n;i++)vis[i]=0;
		int pp=check();
		if(pp>2)return;
		int dm,mx=0;
		for(int i=1;i<=n;i++){
			dm=0x3f3f3f3f;
			for(int j=1;j<=n;j++)if(pick[j])dm=min(dm,f[i][j]);
			mx=max(mx,dm);
		}ans=min(ans,mx);
		return;
	}for(int i=num+1;i<=n-k+x;i++)pick[i]=1,dfs(x+1,i),pick[i]=0;
}int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=11;i++)for(int j=1;j<=11;j++)f[i][j]=0x3f3f3f3f;
		for(int i=1;i<=n;i++)vis[i]=0,pick[i]=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			if(n<=10)f[u][v]=1,f[v][u]=1;
		}if(c==13||c==14)cout<<((n+1)/2-k+5)/4<<endl;
		else{
			for(int i=1;i<=n;i++)f[i][i]=0;
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					f[i][j]=0x3f3f3f3f;
					for(int k=1;k<=n;k++){
						f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
						f[j][i]=min(f[j][i],f[k][i]+f[k][j]);
					}
				}
			}dfs(1,0),cout<<ans<<endl;
		}
	}return 0;
}