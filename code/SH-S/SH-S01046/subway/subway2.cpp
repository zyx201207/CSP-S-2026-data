#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,n,m,d,q;
int w[500010];
int t[510][50010];

set<int>stat[510];
set<int>lin[500010];
int G[510][510]; 
int solve(int x,int y){
	bool vis[510]={false};
	int dis[510]={0};
	int end[510]={0};
	memset(dis,0x3f,sizeof(dis));
	queue<pair<int,int> >q;
	for(auto lne:lin[x]){
		q.push({lne,lne});
		vis[lne]=true;
		dis[lne]=0;
		end[lne]=lne;
	}
	while(!q.empty()){
		int u=q.front().first;
		int lll=q.front().second;
		q.pop();
		for(int i=1;i<=n;i++){
			//printf("i:%lld\n",i);
			if(i==u)continue;
			if(G[u][i]==0x3f3f3f3f)continue;
//			if(dis[u]+G[u][i]<dis[i]&&lin[y].find(i)!=lin[y].end()){
//				dis[i]=dis[u]+G[u][i];
//				end[i]=u;
//				continue;
//			}
			if(vis[i]==true&&dis[u]+G[u][i]<dis[i]){
				dis[i]=dis[u]+G[u][i];
				//printf("%lld %lld %lld\n",u,i,dis[i]);
				end[i]=lll;
				if(lin[y].find(i)!=lin[y].end())continue;
				q.push({i,lll});
			}
			else if(vis[i]==false){
				dis[i]=dis[u]+G[u][i];
				//printf("%lld %lld %lld\n",u,i,dis[i]);
				vis[i]=true;
				end[i]=lll;
				if(lin[y].find(i)!=lin[y].end())continue;
				q.push({i,lll});
			}
		}
	}
	int ans=0x3f3f3f3f;
	int kkksc=0;
	for(auto lne:lin[y]){
		if(dis[lne]<ans){
			ans=dis[lne];
			kkksc=lne;
		}
		//ans=min(ans,dis[lne]);
	}
	return ans+w[x]+w[y]+t[end[kkksc]][x]+t[kkksc][y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	memset(t,0x3f,sizeof(t));
	//memset(G,sizeof(G),0x3f);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			G[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int a,tt;
			scanf("%lld%lld",&a,&tt);
			stat[i].insert(a);
			lin[a].insert(i);
			t[i][a]=tt;
		} 
	}
	for(int i=1;i<=n;i++){
		for(auto p:stat[i]){
			if(lin[p].size()>1){
				//printf("p:%lld\n",p);
				for(auto lne:lin[p]){
					if(lne==i)continue;
					int tme=t[i][p]+t[lne][p];
					//printf("tme:%lld\n",tme);
					G[i][lne]=min(G[i][lne],tme);
					G[lne][i]=G[i][lne];
				}
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		printf("%lld ",G[i][j]);
	//	}
	//	puts("");
	//}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==k)continue;
				if(j==k)continue;
				if(i==j){
					G[i][j]=0;
					G[j][i]=0;
					continue;
				}
				if(G[i][k]!=0x3f3f3f3f and G[j][k]!=0x3f3f3f3f){
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			} 
		} 
	}
	for(int r=1;r<=q;r++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",solve(x,y));
	}
	return 0;
}
