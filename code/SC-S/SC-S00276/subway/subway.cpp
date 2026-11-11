#include<bits/stdc++.h>
#define pii pair<ll,ll>
#define ll long long
using namespace std;
const int N=1e7+5;
struct Edge{
	ll to,nxt,val;
}edge[N];
ll c,n,m,d,T,w[N],ans,k,head[N],cnt,a[N],b[N];
void add(ll x,ll y,ll z){
	edge[++cnt]={y,head[x],z};
	head[x]=cnt;
}
priority_queue<pii,vector<pii>,greater<pii> >  q;
ll dis[N],vis[N];
ll dij(ll st,ll ed){
	while(!q.empty()) q.pop();
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		ll x=q.top().second;
		q.pop();
		if(x==ed) return dis[x];
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].nxt){
			ll y=edge[i].to,d=edge[i].val;
			if(dis[y]>dis[x]+d){
				dis[y]=dis[x]+d;
				if(!vis[y]){
					q.push({dis[y],y});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>b[j];
			add(a[j],a[j]+i*m,b[j]);
			add(a[j]+i*m,a[j],b[j]);
			for(int p=1;p<j;p++){
				add(a[p]+i*m,a[j]+i*m,0);
				add(a[j]+i*m,a[p]+i*m,0);
			}
		}
	}
	while(T--){
		ll x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		ans+=dij(x,y);
		cout<<ans<<"\n";
	}
	return 0;
}

/* 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2




0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/