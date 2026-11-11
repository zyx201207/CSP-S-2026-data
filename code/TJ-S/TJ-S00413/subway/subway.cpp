#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e3+100;
int eekt[N],eett[N][N];
int c,n,m,d,q,a,t,ans[N];
bool creach[N][N];
int cnum[N];
int edge[N][N];
void dfs(int u,int v,int index) {
	int maxx=INT_MAX;
	for(int i=1; i<=n; ++i) {
		if(creach[u][i]&&creach[v][i]) {
			ans[index]+=eett[u][i];
			ans[index]+=eett[v][i];
			return;
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c >>n >>m >>d >>q;
	for(int i=1; i<=m; ++i) {
		cin>>eekt[i];
	}
	for(int i=1; i<=n; ++i) {
		int k;
		cin>>k;
		for(int j=1; j<=k; ++j) {
			cin>>a >>t;
			creach[a][i]=1;
			cnum[a]++;
			edge[a][cnum[a]]=i;
			eett[a][i]=t;
		}
	}
	int start,end;
	for(int i=1; i<=q; ++i) {
		ans[i]=0;
		cin>>start >>end;
		ans[i]+=eekt[start];
		ans[i]+=eekt[end];
		dfs(start,end,i);
	}
    for(int i=1;i<=q;++i) cout<<ans[i]<<'\n';
	return 0;
}
