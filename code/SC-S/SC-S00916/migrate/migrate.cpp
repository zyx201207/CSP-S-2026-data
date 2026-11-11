#include<bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e5+5;
int a[N],hh[N],to[N],nex[N],cnt[N],tot,dis[N],vis[N],n;
priority_queue<P,vector<P>,greater<P>>q;
void add(int u,int v){
	to[++tot]=v;
	nex[tot]=hh[u];
	hh[u]=tot;
}
void dijkstra(int u){
	q.push(mp(0,u));
	memset(dis,0x3f,sizeof(int)*(n+1));
	memset(vis,0,sizeof(int)*(n+1));
	memset(cnt,0,sizeof(int)*(n+1));
	dis[u]=0,cnt[u]=1;
	while(!q.empty()){
		int t=q.top().second;
		q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=hh[t];i;i=nex[i]){
			int v=to[i];
			if(dis[v]>dis[t]+1){
				dis[v]=dis[t]+1;
				cnt[v]=cnt[t];
				if(!vis[v])
					q.push(mp(dis[v],v));
			}
			else if(dis[v]==dis[t]+1){
				cnt[v]+=cnt[t];
				if(!vis[v])
					q.push(mp(dis[v],v));
			}
				
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int js=0,d;cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(hh,0,sizeof(int)*(n+1));
		tot=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)
					add(i,j);
				else break;
			}
		for(int i=1;i<=n;i++){
			dijkstra(i);
			for(int j=1;j<=n;j++)
				js+=(cnt[j]==2);
		}
		cout<<js<<'\n';
	}
	return 0;
}