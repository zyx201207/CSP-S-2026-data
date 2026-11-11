#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define Endl '\n'
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>>ve[500005];
int f[505][505];
int ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			ve[a].emplace_back(i,t);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e18;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<ve[i].size();j++)
			for(int k=0;k<j;k++){
				int u=ve[i][j].first,v=ve[i][k].first,w=ve[i][j].second+ve[i][k].second;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int s,t;
		ans=1e18;
		cin>>s>>t;
		for(int i=0;i<ve[s].size();i++)
			for(int j=0;j<ve[t].size();j++){
				int u=ve[s][i].first,v=ve[t][j].first,cst=ve[s][i].second+ve[t][j].second+w[s]+w[t];
				ans=min(ans,f[u][v]+cst);
			}
		cout<<ans<<endl;
	}
	return 0;
}

