#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
constexpr int N=5e5+5,inf=1.5e18;
int w[N],a[505][505];
vector<pair<int,int>> crs[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,ai,ti;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ai>>ti;
			crs[ai].push_back({i,ti});
		}
		for(int j=1;j<=n;j++){
			a[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		vector<pair<int,int>> &ths=crs[i];
		for(int j=0;j<ths.size();j++){
			for(int k=0;k<ths.size();k++){
				if(j==k)a[ths[j].first][ths[k].first]=0;
				else a[ths[j].first][ths[k].first]
				//=a[ths[k].first][ths[j].second]
				=min(ths[j].second+ths[k].second,
				a[ths[j].first][ths[k].first]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<crs[x].size();i++){
			for(int j=0;j<crs[y].size();j++){
				ans=min(ans,
				a[crs[x][i].first][crs[y][j].first]
				+crs[x][i].second+crs[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}