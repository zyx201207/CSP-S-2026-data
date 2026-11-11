#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,m,n,d,q,w[500005],a[500005][2],from[500005],cnt;
vector<pair<int, int> > v[500005];
int f[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,x;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j][0]>>a[j][1];
			v[a[j][0]].push_back({i,a[j][1]});
		}
		for(int j=1;j<=n;j++){
			f[i][j]=INT_MAX;
			if(i==j) f[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<j;k++){
				f[v[i][j].first][v[i][k].first]=f[v[i][k].first][v[i][j].first]=min(f[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i!=k&&j!=k){
					f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--){
		int x,y,ans=INT_MAX;
		cin>>x>>y;
		for(int i=0;i<v[x].size();i++){
			for(int j=0;j<v[y].size();j++){
				int ret=f[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second+w[x]+w[y];
				ans=min(ans,ret);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
