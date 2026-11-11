#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10,inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M],k[N],a,t,dp[N][N],x,y,s[M];
struct node{
	int a,t;
};
vector<node>g[N];
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
			s[a]=i;
			g[a].push_back({i,t});
		}	
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<g[i].size();j++)
			for(int k=0;k<g[i].size();k++)
				dp[g[i][j].a][g[i][k].a]=min(dp[g[i][j].a][g[i][k].a],g[i][j].t+g[i][k].t);
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+(dp[s[x]][s[y]]==inf?0:dp[s[x]][s[y]])+w[y]<<"\n";
	}
	return 0;
}
//死了，1=没了
//展示我代码的是给！！！
