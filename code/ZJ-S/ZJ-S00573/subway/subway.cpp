#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+1000+10,M=500+500;
int c,n,m,l,q,jd;
vector<pair<int,int> >v[N];
int f[M][M];
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>l>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		while(w--){
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				f[v[i][j].first][v[i][k].first]=min(f[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
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
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int minn=LONG_LONG_MAX;
		for(int j=0;j<v[x].size();j++){
			for(int k=0;k<v[y].size();k++){
				minn=min(minn,v[x][j].second+f[v[x][j].first][v[y][k].first]+v[y][k].second);
			}
		}
		cout<<minn+a[x]+a[y]<<"\n";
	}
	return 0;
}