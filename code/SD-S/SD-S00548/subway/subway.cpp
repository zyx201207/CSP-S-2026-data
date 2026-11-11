#include<bits/stdc++.h>
#define l(x) ((x)&-(x))
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define A first
#define B second
#define CT continue
#define rt return
#define umap unordered_map
#define pq priority_queue
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int N=5e2+10;
const int M=5e5+10;
const int LOG=21;
const ll inf=1e12;
int C,n,m,d,T,x,y,k,a,t,w[M],s;
ll dp[N][N],res;
vector<pii> v[M];//idx,len
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	cout<<fixed<<setprecision(2);
	cin>>C>>n>>m>>d>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			{cin>>a>>t;v[a].pb({i,t});}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
			if(i!=j) dp[i][j]=inf;
	for(int i=1;i<=m;i++)
		for(int j=0;j<v[i].size();j++)
			for(int k=0;k<j;k++){
				x=v[i][j].A,y=v[i][k].A;
				dp[x][y]=dp[y][x]=min(dp[x][y],
				(ll)(v[i][j].B+v[i][k].B));
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][k]!=inf&&dp[k][j]!=inf)
					dp[i][j]=min(dp[i][j],
					dp[i][k]+dp[k][j]);
	while(T--){
		cin>>x>>y;res=inf;
		for(int i=0;i<v[x].size();i++)
			for(int j=0;j<v[y].size();j++)
				s=v[x][i].A,t=v[y][j].A,
				res=min(res,dp[s][t]+
				v[x][i].B+v[y][j].B);
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
/*

*/
