#include<bits/stdc++.h>
using namespace std;
int C,T,n,dis[5005],num[5005],vis[5005];
long long a[5005],d,ans;
vector<int> g[5005];
void dfs(int x,int step){
	if(step==dis[x]) num[x]++;
	for(int i=0;i<g[x].size();i++){
		dfs(g[x][i],step+1);
	}return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,k;i<=n;i++){
			scanf("%lld",&a[i]);
			//cout<<a[i]<<" "<<a[i]-a[i-1]<<endl;
			k=i-1;
			while(k>0&&a[i]-a[k]<=d){
			//	cout<<k<<" "<<i<<endl;
				g[k].push_back(i);
				k--;
			}
		}
		for(int i=1,u,v;i<=n;i++){
			priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
			for(int j=1;j<=n;j++) dis[j]=1000000000,num[j]=0,vis[j]=0;
			q.push({0,i});
			dis[i]=0;
			while(!q.empty()){
				u=q.top().second;
				q.pop();
				if(vis[u]) continue;
				vis[u]=1;
				//cout<<u<<endl;
				for(int j=0;j<g[u].size();j++){
					v=g[u][j];
					if(dis[v]>dis[u]+1) dis[v]=dis[u]+1;
					//else if(dis[v]==dis[u]+1) num[v]++;
					q.push({dis[v],v});
				}
			}for(int i=1;i<=n;i++) vis[i]=0;
			
			dfs(i,0);
			for(int j=1;j<=n;j++){
				if(num[j]==2){
				//	cout<<i<<" "<<j<<" "<<dis[j]<<endl;
					ans++;
				}
				//cout<<i<<" "<<j<<" "<<dis[j]<<" "<<num[j]<<endl;
			}
		}printf("%lld\n",ans);
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<g[i].size();j++){
//				cout<<i<<" "<<g[i][j]<<endl;
//			}
//		}
	}
	return 0;
} 
