#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int c,n,m,d,Q;
int w[N];
struct node{int a,t;};
struct edge{int v,w;};
vector<node> q[N];
bool f=1;
int dp[N][N];
edge p[N];
void fl(){
	int inf=1e9+7;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dp[i][j]=0;
			else dp[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][p[i].v]=p[i].w;
		dp[p[i].v][i]=p[i].w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][k]!=inf && dp[j][k]!=inf){
					if(dp[i][k]+dp[j][k]<dp[i][j]){
						dp[i][j]=dp[i][k]+dp[j][k];
					}
				}
			}
		}
	}
}
void solve1(){
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int i=1,a,t;i<=k;i++){
			cin>>a>>t;
			q[i].push_back({a,t});
		}
		if(k>2)f=0;
	}
	
	for(int i=1;i<=n;i++){
		node u=q[i][0],v=q[i][1];
		p[u.a]={v.a,u.t+v.t};
		p[v.a]={u.a,u.t+v.t};
	}
	fl();
	for(int i=1,x,y,ans;i<=Q;i++){
		ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<ans+dp[x][y]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
