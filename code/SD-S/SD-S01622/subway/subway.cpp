#include<bits/stdc++.h>
using namespace std;
const int N=500,M=10000;
int c,n,m,d,q,ans,a[N][M],t[N][M],k[N],w[N];
bool vis[N][M];
void dfs(int x,int wh,int now,int e,int la) {
	if(la==e) {
		ans=min(ans,now);
		return;
	}
//	cout<<"["<<x<<' '<<ans<<']'<<' ';
//	cout<<"ต๗สิ"<<x<<' '<<wh<<' '<<now<<' '<<e<<'\n';
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=k[i];j++) {
			if(vis[x][a[i][j]]) {
				dfs(a[i][j],i,now+t[i][j],e,x);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			if(j!=1) vis[a[i][j-1]][a[i][j]]=1;
		}
	}
	while(q--) {
		int s,e;cin>>s>>e;
		ans=INT_MAX;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=k[i];j++) {
				if(a[i][j]==s) {
					dfs(s,i,t[i][j],e,-1);
				}
			}
		}
		cout<<ans+w[s]+w[e]<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
