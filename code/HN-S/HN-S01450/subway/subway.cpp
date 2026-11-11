#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1005;
ll c,n,m,d,Q,w[maxn],a,t,dis[maxn+500][maxn+500],vis[maxn+500],ans[maxn][maxn];
vector<ll>q[maxn+510];
queue<int>P;
ll solve(int st,int en){
	for(int i=1;i<=maxn+495;i++){
		vis[i]=1e18;
	}
	vis[st]=0;
	P.push(st);
	while(!P.empty()){
		int u=P.front();
//		cout<<u<<' '<<vis[u]<<'\n';
		for(int o=0;o<q[u].size();o++){
			ll v=q[u][o];
			if(vis[u]+dis[u][v]<vis[v]){
				vis[v]=vis[u]+dis[u][v];
				P.push(v);
			}
		}
		P.pop();
	}
	return vis[en];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		if(9<=c&&c<=11){
			if(k==2){
				int a1,a2,t1,t2;
				scanf("%d%d%d%d",&a1,&a2,&t1,&t2);
				cin>>a1>>a2>>t1>>t2;
				q[a1].push_back(a2);
				q[a2].push_back(a1);
				dis[a1][a2]=t1+t2;
				dis[a2][a1]=t1+t2;
			}
			continue;
		}
		for(int j=1;j<=k;j++){
			ll tot;
			scanf("%d%d",&a,&t);
			q[1000+i].push_back(a);
			q[a].push_back(1000+i);
			dis[a][1000+i]=t;
			dis[1000+i][a]=t;
		}
	}
	while(Q--){
		int st,en;
		scanf("%d%d",&st,&en);
		if(ans[st][en]==0)ans[st][en]=solve(st,en);
		ans[en][st]=ans[st][en];
		printf("%lld\n",ans[st][en]+w[st]+w[en]);
	}
	return 0;
}

