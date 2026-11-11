#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int M=500005;
const long long inf=LLONG_MAX/10;
int c,n,m,d,q;
int w[M];
int e[N][N];
int f[N][N];
vector<pair<int,int> > a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			e[i][j]=inf;
	for(int i=1;i<=n;i++)
		e[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		int len=a[i].size();
		for(int j=0;j<len;j++){
			for(int k=0;k<len;k++){
				if(j==k) continue;
				int t1=a[i][j].first;
				int t2=a[i][k].first;
				e[t1][t2]=min(e[t1][t2],a[i][j].second+a[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int z=1;z<=n;z++)
				e[j][z]=min(e[j][z],e[j][i]+e[i][z]);
	while(q--){
		int x,y,ans=inf;
		cin>>x>>y;
		int len1=a[x].size();
		int len2=a[y].size();
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++)
				ans=min(ans,e[a[x][i].first][a[y][j].first]+a[x][i].second+a[y][j].second+w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}