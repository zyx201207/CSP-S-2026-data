#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
vector<int> g[505];
vector<int> t[505];
vector<int> sum[500005];
vector<int> la[500005];
int e;
int ans=1e18;
int vis[500005];
void dfs(int x,int res,int l) {
//	cout<<x<<"\n";
	if(x==e) {
		int cnt=0;
		for(int k=0; k<g[l].size(); k++) {
			if(g[l][k]==x) {
				cnt+=t[l][k];
			}
		}
//		cout<<l<<" "<<cnt<<" "<<res<<"\n";
		ans=min(ans,res+cnt);
		return ;
	}
	if(res>=ans) return;
	for(int p=0; p<sum[x].size(); p++) {
		int cnt=0;
		if(sum[x][p]!=l) {
			for(int i=0; i<sum[x].size(); i++) {
				if(sum[x][i]==l) cnt+=t[l][la[x][i]];
			}
			cnt+=t[sum[x][p]][la[x][p]];
		}
		for(int i=0; i<g[sum[x][p]].size(); i++) {
			if(vis[g[sum[x][p]][i]]==0) {
				vis[g[sum[x][p]][i]]=1;
				dfs(g[sum[x][p]][i],res+cnt,sum[x][p]);
				vis[g[sum[x][p]][i]]=0;
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int x;
		cin>>x;
		for(int j=1; j<=x; j++) {
			int a,tt;
			cin>>a>>tt;
//			cout<<a<<" "<<tt<<" ";
			sum[a].push_back(i);
			g[i].push_back(a);
			t[i].push_back(tt);
			la[a].push_back(j-1);
//			cout<<sum[a][sum[a].size()-1]<<"\n";
		}
//		cout<<"\n";
	}
//	for(int i=1; i<=m; i++) {
//		for(int j=0; j<sum[i].size(); j++) {
//			cout<<sum[i][j]<<" "<<la[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--) {
		int s;
		cin>>s>>e;
		ans=1e18;
		for(int i=0; i<sum[s].size(); i++) {
			vis[s]=1;
			dfs(s,t[sum[s][i]][la[s][i]],sum[s][i]);
//			memset(vis,0,sizeof vis);
			vis[s]=0;
		}
		cout<<ans+w[s]+w[e]<<"\n";
	}
	return 0;
}
/*
0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
*/
