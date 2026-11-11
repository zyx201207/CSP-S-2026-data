#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define fi first
#define se second
const int N=5e2+7;
const int M=1e6+7;
int C,n,m,d,q;
int k[N],w[M],f[N][N];
vector<pi>e[M];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,t;cin>>x>>t;
			e[x].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto v:e[i]){
			for(auto u:e[i]){
				int k=v.fi,w1=v.se,j=u.fi,w2=u.se;
				f[k][j]=f[j][k]=min(f[k][j],w1+w2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		int ans=2e18;
		for(auto v:e[x]){
			for(auto u:e[y]){
				int i=v.fi,w1=v.se,j=u.fi,w2=u.se;
				ans=min(ans,w[x]+w[y]+w1+w2+f[i][j]);
			}
		}
		cout<<ans<<'\n';
	}
	
}