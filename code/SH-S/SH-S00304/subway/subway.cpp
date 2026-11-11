#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,ll> pil;
constexpr int maxn=5e5+10;
constexpr int MAXN=510;
constexpr ll inf=1e17;
int ID,n,m,dd,q;
int w[maxn];
vector<pil> g[maxn];
ll dis[MAXN][MAXN];
bool vis[MAXN];
ll b[maxn],c[maxn];
//vector<pil>f[MAXN];
inline void solve(){
	for(int i=1;i<=m;i++)cin>>w[i];
	if(n==1){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int p;
				ll d;
				cin>>p>>d;
				b[p]=d;
			}
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			ll ans=b[l]+b[r]+w[l]+w[r];
			cout<<ans<<'\n';
		}
		return;
	}
	//n=2
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			ll d;
			cin>>p>>d;
			if(i==1)b[p]=d;
			else c[p]=d;
		}
	}
		ll cost=inf;
		for(int i=1;i<=m;i++){
			if(b[i]&&c[i]){
				cost=min(cost,b[i]+c[i]);
			}
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			ll ans=inf;
			
			if(b[l]&&b[r])ans=min(ans,b[l]+b[r]);
			if(c[l]&&c[r])ans=min(ans,c[l]+c[r]);
			if(b[l])ans=min(ans,b[l]+c[r]+cost);
			else ans=min(ans,b[r]+c[l]+cost);
			ans+=w[l]+w[r];
			cout<<ans<<'\n';
		}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>ID>>n>>m>>dd>>q;
	if(ID==20||ID==21){
		solve();
		return 0;
	}
	//init
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=inf;
		}
	}
	//
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int p;
			ll d;
			cin>>p>>d;
			g[p].push_back({i,d});
		}
	}
	for(int i=1;i<=m;i++){
		if(g[i].size()==0)continue;
		//int cnt=g[i].size();
		//d*d
		for(auto x : g[i]){
			for(auto y : g[i]){
				//pil x=g[i][j],y=g[i][k];
				int u=x.first,v=y.first;
				if(u==v)continue;
				//
				//a[u][v]=a[v][u]=1;
				//
				//ll w1=x.second,w2=y.second;
				//int l=min(u,v),r=max(u,v);
				dis[u][v]=min(dis[u][v],1ll*x.second+y.second);
				dis[v][u]=dis[u][v];
				//f[u].push_back({v,x.second+y.second});
				//f[v].push_back({u,x.second+y.second});
				//dis[u][v]=min(dis[u][v],w1+w2);
			}
		}
	}
		/*
		//floyd
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					dis[i][j]=min(dis[i][k],dis[k][j]);
				}
			}
		}
		*/
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
		}
	}
	*/
	//dijkstra
	for(int i=1;i<=n;i++){
		int num=n-i;
		for(int j=i+1;j<=n;j++)vis[j]=0;
		vis[i]=1;
		//int l,r;
		for(int u=1;u<=i-1;u++){
			for(int v=i+1;v<=n;v++){
				if(v==i||v==u)continue;
				dis[i][v]=min(dis[i][v],dis[i][u]+dis[v][u]);
				dis[v][i]=dis[i][v];
			}
		}
		while(num){
			int u=0;
			ll d=inf;
			for(int j=i+1;j<=n;j++){
				if(vis[j])continue;
				//l=min(i,j),r=max(i,j);
				if(dis[i][j]<d){//dis[i][j]<d
					u=j;
					d=dis[i][j];
				}
			}
			vis[u]=1;
			/*
			if(g[u].size()==0){
				num--;
				continue;
			}
			*/
				/*
				int cnt=g[u].size();
			
				for(int j=0;j<cnt;j++){
					pil x=g[u][j];
					int v=x.first;
					//l=min(i,v),r=max(i,v);
					//dis[i][v]=min(dis[i][v],dis[i][u]+dis[u][v]);
					dis[min(i,v)][max(i,v)]=min(dis[min(i,v)][max(i,v)],dis[min(i,u)][max(i,u)]+dis[min(v,u)][max(v,u)]);
				}
				*/
			for(int v=1;v<=n;v++){
				if(v==i||v==u)continue;
				dis[i][v]=min(dis[i][v],dis[i][u]+dis[v][u]);
				dis[v][i]=dis[i][v];
			}
			num--;
		}
	}
	//
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<i<<' '<<j<<' '<<dis[i][j]<<'\n';
		}
	}
	*/
	while(q--){
		int l,r;
		cin>>l>>r;
		ll ans=inf;
		//int cnt1=g[l].size(),cnt2=g[r].size();
		/*
		for(int i=0;i<cnt1;i++){
			pil x=g[l][i];
			int u=x.first;
			for(int j=0;j<cnt2;j++){
				pil y=g[r][j];
				int v=y.first;
				ll w1=x.second,w2=y.second;
				ll res=w[l]+w[r]+w1+w2+dis[min(u,v)][max(u,v)];
				ans=min(ans,res);
			}
		}
		*/
		for(auto x : g[l]){
			int u=x.first;
			for(auto y : g[r]){
				int v=y.first;
				//ll w1=x.second,w2=y.second;
				//ll res=w[l]+w[r]+w1+w2+dis[min(u,v)][max(u,v)];
				ll res=1ll*w[l]+w[r]+x.second+y.second+dis[u][v];
				ans=min(ans,res);
			}
		}
		/*
		for(int i=0;i<cnt1;i++){
			for(int j=0;j<cnt2;j++){
				pil x=g[l][i],y=g[r][j];
				int u=x.first,v=y.first;
				ll w1=x.second,w2=y.second;
				ll res=w[l]+w[r]+w1+w2+dis[u][v];
				if(ans==res){
					cout<<u<<' '<<v<<'\n';
				}
			}
		}
		*/
		cout<<ans<<'\n';
	}
	return 0;
}
