#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=20;
ll c,t,n,k,i,x,y,mi,m,j,cnt,d[N],vis[N],dis[N][N],ma,K;
typedef pair<ll,ll> pll;
priority_queue<pll,vector<pll>,greater<pll> > q;
vector<ll> v[N];
void dfs(ll x,ll bit){
	ll i,sx;
	vis[x]=1;
	for(i=0;i<v[x].size();i++){
		sx=v[x][i];
		if(vis[sx])continue;
		if(!(bit&(1<<(sx-1))))continue;
		dfs(sx,bit);
	}
}
void dij(ll x){
	ll fx,i,sx,sb;
	q.push({0,x});dis[x][x]=0;
	while(!q.empty()){
		fx=q.top().second;q.pop();
		for(i=0;i<v[fx].size();i++){
			sx=v[fx][i];sb=dis[x][fx]+1;
			if(sb<dis[x][sx]){
				dis[x][sx]=sb;
				q.push({sb,sx});
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>K;mi=2e18;
		for(i=1;i<=n;i++)v[i].clear();
		for(i=1;i<n;i++){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		m=(1<<n)-1;
		for(i=0;i<=m;i++){
			memset(vis,0,sizeof(vis));
			cnt=0;
			for(j=1;j<=n;j++)
				if(i&(1<<(j-1)))
					cnt++;
			if(cnt!=K)continue;
//			cout<<"¶ÔÓÚi="<<i<<"\n";
//			for(j=1;j<=n;j++){
//				for(k=1;k<=n;k++)
//					cout<<dis[j][k]<<" ";
//				cout<<"\n";
//			}
			cnt=0;
			for(j=1;j<=n;j++)
				if(i&(1<<(j-1))&&vis[j]==0)
					dfs(j,i),cnt++;
			if(cnt>2)continue;
			memset(dis,127,sizeof(dis));
			for(j=1;j<=n;j++) 
				if(i&(1<<(j-1)))
					dij(j);
//			dij(2);
			memset(d,127,sizeof(d));
			for(j=1;j<=n;j++)
				for(k=1;k<=n;k++)
					if(i&(1<<(k-1)))
						d[j]=min(d[j],dis[k][j]);
			ma=0;
			for(j=1;j<=n;j++)
				ma=max(ma,d[j]);
			if(ma<mi)mi=min(mi,ma);
		}
		cout<<mi;
		if(t!=0)cout<<"\n";
	}
	return 0;
}

