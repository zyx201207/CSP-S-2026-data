#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn=510,Maxm=2e4+10;//dfs 60pts期望 非人写不出来  
int c,n,m,d,q;
int w[Maxm],a[Maxn][Maxm],t[Maxn][Maxm],vis[Maxm];
vector <int> G[Maxm];
int ans;
void dfs(int x,int y,int sum){
	for(auto it:)
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=n;j++){
			G[a[i][j-1]].push_back(a[i][j]);
			G[a[i][j]].push_back(a[i][j-1]);//建图 
		}
	} 
	while(q--){
		int x,y;cin>>x>>y;
		ans=0;
		for(int i=1;i<=m;i++)	vis[i]=0;
		dfs(x,y,0);
		cout<<ans;
	}
	return 0;
} 
