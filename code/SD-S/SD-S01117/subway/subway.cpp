#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<pair<int,int>> v[500005];//可到达站厅 时间 
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto x:v[i]){
			for(auto y:v[i]){
				f[x.first][y.first]=min(f[x.first][y.first],x.second+y.second);
				f[y.first][x.first]=min(f[y.first][x.first],x.second+y.second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto tp1:v[x]){
			for(auto tp2:v[y]){
				ans=min(ans,tp1.second+tp2.second+f[tp1.first][tp2.first]+w[x]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
