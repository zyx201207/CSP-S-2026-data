#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+10,inf=4e18;
int c,n,m,d,q,f[N][N],w[M],k[M];
vector<pair<int,int> >g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x>>t;
			g[x].push_back({i,t});
//			cout<<x<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int x1=g[i][j].first,t1=g[i][j].second;
				int x2=g[i][k].first,t2=g[i][k].second;
				f[x1][x2]=f[x2][x1]=min(f[x1][x2],t1+t2);
//				cout<<x1<<" "<<x2<<" "<<f[x1][x2]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		for(auto z1:g[x]){
			for(auto z2:g[y]){
				int x1=z1.first,t1=z1.second;
				int x2=z2.first,t2=z2.second;
				ans=min(ans,f[x1][x2]+t1+t2);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
