#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int sid,n,m,a[maxn],d,Q,ans,x,y,z,f[510][510];
vector<pair<int,int> >han[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>sid>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>y>>z;
			han[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<han[i].size();j++){
			for(int k=0;k<han[i].size();k++){
				f[han[i][j].first][han[i][k].first]=min(f[han[i][j].first][han[i][k].first],han[i][j].second+han[i][k].second);
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
	while(Q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<han[x].size();i++){
			for(int j=0;j<han[y].size();j++){
				ans=min(ans,han[x][i].second+han[y][j].second+f[han[x][i].first][han[y][j].first]);
			}
		}
		ans+=a[x];
		ans+=a[y];
		cout<<ans<<'\n';
	}
	return 0;
}
