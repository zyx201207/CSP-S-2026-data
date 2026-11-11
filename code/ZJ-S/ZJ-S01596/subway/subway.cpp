#include<bits/stdc++.h>
#include<ctime>
#define int long long
#define PII pair<int,int>
#define mk(a,b) make_pair(a,b)
using namespace std;
const int N=5e2+10,M=5e5+10,inf=1e18;
int C,n,m,D,q;
int w[M];
vector<PII> a[M];
int dis[N][N];
void Min(int &a,int b){
	if(b<a) a=b;
	return;
}
void solve(){

	cin>>n>>m>>D>>q;

	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		int sz=0;
		cin>>sz;
		for(int j=1;j<=sz;++j){
			int x,t;
			cin>>x>>t;
			a[x].push_back(mk(i,t));
		}
	}

	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=(i==j?0:inf);

	for(int i=1;i<=m;++i){
		int sz=a[i].size();
		for(int j=0;j<sz;++j){
			int s=a[i][j].first,vals=a[i][j].second;
			for(int k=0;k<sz;++k){
				if(j==k) continue;
				int t=a[i][k].first,valt=a[i][k].second;
				Min(dis[s][t],vals+valt);
				Min(dis[t][s],vals+valt);
			}
		}
	}

	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				Min(dis[i][j],dis[i][k]+dis[k][j]);

	while(q--){
		int s,t;
		cin>>s>>t;
		if(s==t){
			cout<<"0\n";
			continue;
		}
		int ans=inf,cur=w[s]+w[t];
		for(auto ps:a[s])
			for(auto pt:a[t])
				Min(ans,ps.second+pt.second+dis[ps.first][pt.first]+cur);

		cout<<ans<<"\n";
	}

	return;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int T=1;
	// cin>>T;
	cin>>C;
	while(T--) solve();

	// cerr<<1e3*clock()/CLOCKS_PER_SEC<<"ms\n";
	return 0;
}