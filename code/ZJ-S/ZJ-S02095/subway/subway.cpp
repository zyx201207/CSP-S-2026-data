#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,ques,cnt=0;
int w[500005],p[500005],a[500005][25],vis[505],head[505],to[505],nxt[250005];
long long val[500005][25],vv[250005],dis[505][505],s[505][505],ans;
vector<pair<int,int> > g[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&ques);
	for(int i=1;i<=n;i++){
		head[i]=-1;
		for(int j=i+1;j<=n;j++) s[i][j]=dis[i][j]=1000000000000000;
	}
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1,u,kk;i<=n;i++){
		scanf("%d",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%d",&u);
			scanf("%lld",&val[u][++p[u]]);
			a[u][p[u]]=i;
		}
	}int x,y;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p[i];j++){
			for(int k=1;k<j;k++){
				x=a[i][k];
				y=a[i][j];
				dis[x][y]=min(dis[x][y],val[i][j]+val[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dis[i][j]<1000000000000000){
				to[cnt]=j;
				vv[cnt]=dis[i][j];
				nxt[cnt]=head[i];
				head[i]=cnt++;
				//g[i].push_back({j,dis[i][j]});
				//g[j].push_back({i,dis[i][j]});
			}
		}
	}
	for(int i=1,u,v;i<=n;i++){
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		for(int j=1;j<=n;j++) vis[j]=0;
		q.push({0,i});
		s[i][i]=0;
		while(!q.empty()){
			u=q.top().second;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(int j=head[u];j!=-1;j=nxt[j]){
				v=to[j];
				s[i][v]=min(s[i][v],s[i][u]+vv[j]);
				q.push({s[i][v],v});
			}
//			for(int j=0;j<g[u].size();j++){
//				v=g[u][j].first;
//				s[i][v]=min(s[i][v],s[i][u]+g[u][j].second);
//				q.push({s[i][v],v});
//			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			s[j][i]=s[i][j];
		}
	}
	for(int i=1,u,v;i<=ques;i++){
		scanf("%d%d",&u,&v);
		ans=1000000000000000;
		for(int j=1;j<=p[u];j++){
			for(int k=1;k<=p[v];k++){
				ans=min(ans,s[a[u][j]][a[v][k]]+val[u][j]+val[v][k]+w[u]+w[v]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
