#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c,n,m,d,Q; 
int w[500005];
vector<pair<int,int> >f[500005];
long long dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);////////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int cnt=0;
	int k;
	int a,t;
//	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>k;
//		sum+=k; 
		for(int j=1;j<=k;j++){
			cnt++;
			cin>>a>>t;
			f[a].push_back({i,t});
		}
	}
//	cerr<<sum<<endl;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int p=f[i].size();
		for(int j=0;j<p;j++){
			int da=f[i][j].first;
			long long ha=f[i][j].second;
			for(int k=0;k<p;k++){
				if(j==k){
					continue;
				}
				int db=f[i][k].first;
				long long hb=f[i][k].second;
				dis[da][db]=min(dis[da][db],ha+hb);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		int us=f[u].size();
		int vs=f[v].size();
		long long ans=1e18;
		for(int i=0;i<us;i++){
			long long da=f[u][i].first,ha=f[u][i].second;
			for(int j=0;j<vs;j++){
				long long db=f[v][j].first,hb=f[v][j].second;
				ans=min(ans,ha+hb+dis[da][db]);
			}
		} 
//		cout<<ans<<endl;
//		cout<<w[u]<<' '<<w[v]<<endl;
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}