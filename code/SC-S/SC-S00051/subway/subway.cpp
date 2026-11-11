#include<bits/stdc++.h>
#define int long long
#define cin std::cin
#define cout std::cout
#define endl '\n'
using namespace std;
const int maxn=1e3+5;
int c,n,m,d,q;
int t[maxn];
struct node{int to,w;};
vector<node> vt[maxn];
int dp[maxn];
int ans[maxn][maxn];
void init(){
	for(int i=1;i<=2*m;i++) dp[i]=0x7f7f7f7f7f7f7f7f;
}
int dij(int u,int v){
	init();
	queue<int> q;
	q.push(u); dp[u]=0;
	while(!q.empty()){
		int top=q.front(); q.pop();
		for(auto no:vt[top]){
			if(dp[no.to]>dp[top]+no.w){
				dp[no.to]=dp[top]+no.w;
				q.push(no.to);
			}
		}
		
	}
//	for(int i=1;i<=2*m;i++) cout<<dp[i]<<" ";
//	cout<<endl;
	ans[u][v]=dp[v];
	ans[v][u]=dp[v];
	return dp[v];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(ans,0,sizeof(ans));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int to,w; cin>>to>>w;
			vt[i].push_back({to+m,w});
			vt[to+m].push_back({i,w});
		}
	}
	while(q--){
		int u,v; cin>>u>>v;
		if(ans[u][v]) cout<<ans[u][v]<<endl; 
		else cout<<t[u]+t[v]+dij(u+m,v+m)<<endl;
	}
	return 0;
}