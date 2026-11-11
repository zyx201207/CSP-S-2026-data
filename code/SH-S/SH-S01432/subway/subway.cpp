#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
const int N=505,M=5e5+5;
int a[M],t[M],w[M],k[N];
int f[N][N];
vector<pii> sta[M];
priority_queue<pii,vector<pii>,greater<pii>> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,n,m,d,Q;
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) f[i][j]=f[j][i]=1e18;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			sta[a[j]].push_back({i,t[j]});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto u:sta[i]){
			for(auto v:sta[i]){
				f[u.first][v.first]=min(f[u.first][v.first],u.second+v.second);
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][u]+f[u][j]);
			}
		}
	}
	while(Q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(auto u:sta[x]){
			for(auto v:sta[y]){
				ans=min(ans,f[u.first][v.first]+u.second+v.second+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
