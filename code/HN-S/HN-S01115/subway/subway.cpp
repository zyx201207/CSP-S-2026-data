#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+9,M=5e5+9;
int a[M];
int mx;
int n,m,d,q;
//int has[N][M];
int dp[N][N];
vector<pair<int,int> >v[M];
void florr(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
/*
m个地铁口
n个线路 
q个查询 
*/
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int CSPjiayou;
	cin>>CSPjiayou;
	cin>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			int x,w;
			cin>>x>>w;
			for(auto k:v[x]){
				dp[i][k.first]=dp[k.first][i]=w+k.second;
			}
			v[x].push_back({i,w});
		}
	}
	florr();
	while(q--){
		int x,y;
		cin>>x>>y;
		int mn=1e18;
		for(auto i:v[x]){
			for(auto j:v[y]){
				mn=min(mn,dp[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<mn+a[x]+a[y]<<'\n';
	}
	return 0;
} 
