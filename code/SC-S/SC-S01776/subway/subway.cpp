#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int nxt,to,w;
} e[20000010];
int head[2000010],tot=0;
int w[500010],k[500010],a,t[500010];
int tt[10000010];
void add(int u,int v,int w){
	e[++tot]={head[u],v,w};
	head[u]=tot;
	return;
}
vector<int> tmp[500010];
int c,n,m,d,q;
unordered_map<int,pair<int,int>> mp;
map<pair<int,int>,int> mp1;
int dis[10000010],cnt[500010];
bool vis[10000010];
void dijkstra(int st){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
	for(int i=1;i<=d*m+d;i++){
		vis[i]=0;
		dis[i]=1e10;
	}
	for(int i=1;i<=cnt[st];i++){
		//(i,st)
		q.push({tt[i+d*st],i+d*st});
		dis[st*d+i]=tt[i+d*st];
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){	
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
void subtask1(){
	dijkstra(0);
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
//		if(mp1[{s,e}]!=0){
//			cout<<mp1[{s,e}]<<'\n';
//			continue;
//		}
		int ans=1e10,ans1=1e10;
		for(int j=1;j<=cnt[e];j++){
			//(j,k)->k*d+j
			ans=min(ans,dis[e*d+j]+tt[e*d+j]);
		}
		for(int j=1;j<=cnt[s];j++){
			//(j,k)->k*d+j
			ans1=min(ans1,dis[s*d+j]+tt[s*d+j]);
		}
		ans+=ans1;
		ans+=(w[s]+w[e]);
		mp1[{s,e}]=ans;
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cin>>a>>t[1];
		cnt[a]++;
		tt[a*d+cnt[a]]=t[1];
		tmp[a].push_back(a*d+cnt[a]);
		int lst=a;
		for(int j=2;j<=k[i];j++){
			cin>>a>>t[j];
			cnt[a]++;
			tt[a*d+cnt[a]]=t[j];
			tmp[a].push_back(a*d+cnt[a]);
			add(lst*d+cnt[lst],a*d+cnt[a],0);
			add(a*d+cnt[a],lst*d+cnt[lst],0);
			lst=a;
		}
	}
	if(q*m>100000000){
		subtask1();
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<tmp[i].size();j++){
			for(int k=0;k<tmp[i].size();k++){
				if(j==k) continue;
				add(tmp[i][j],tmp[i][k],tt[tmp[i][j]]+tt[tmp[i][k]]);
				add(tmp[i][k],tmp[i][j],tt[tmp[i][j]]+tt[tmp[i][k]]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		if(mp1[{s,e}]!=0){
			cout<<mp1[{s,e}]<<'\n';
			continue;
		}
		dijkstra(s);
		int ans=1e10;
		for(int j=1;j<=cnt[e];j++){
			//(j,k)->k*d+j
			ans=min(ans,dis[e*d+j]+tt[e*d+j]);
		}
		ans+=(w[s]+w[e]);
		mp1[{s,e}]=ans;
		cout<<ans<<'\n';
	}
	return 0;
}