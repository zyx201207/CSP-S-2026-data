#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,a[11],b[11],dis[11],vis[11],ans=INT_MAX,ll[11];
vector<int>g[11];
void dfs2(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==fa)continue;
		if(a[g[u][i]]==1){
			a[g[u][i]]=0;
			dfs2(g[u][i],u);
		}
	}
}
int SPFA(int x,int y){
	for(int j=1;j<=n;j++){
		dis[j]=INT_MAX;
		vis[j]=0;
	}
	queue<int>q;
	q.push(x);
	dis[x]=0;
	vis[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			if(1+dis[u]<dis[g[u][i]]){
				dis[g[u][i]]=1+dis[u];
				//cout<<"get9uygre";
				if(!vis[g[u][i]]){
					vis[g[u][i]]=1;
					q.push(g[u][i]);
				}
			}
		}
	}
	//for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	return dis[y];
}
void dfs1(int kk){
	if(kk==n+1){
		int f=0;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
			if(a[i]==1){
				f++;
			}
		}
		if(f==k){
			int s=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					dfs2(i,-1);
					s++;
				}
			}
			//cout<<s<<"\n";
			if(s<=2){
				int maxx=0;
				for(int i=1;i<=n;i++){
					if(!b[i]){
						int minn=INT_MAX;
						for(int j=1;j<=n;j++){
							if(b[j]){
								minn=min(minn,SPFA(i,j));
								//cout<<SPFA(i,j)<<" ";
								//cout<<i<<" "<<j<<" ";
							}
						}
						maxx=max(maxx,minn);
					}
				}
				ans=min(ans,maxx);
			}
		}
	}
	else{
		a[kk]=1;
		dfs1(kk+1);
		a[kk]=0;
		dfs1(kk+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		memset(ll,0,sizeof ll);
		ans=INT_MAX;
		cin>>n>>k;
		//vector<int>g[11];
		memset(g,0,sizeof g);
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1);
		cout<<ans<<"\n";
	}
	return 0;
}
