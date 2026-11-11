#include <bits/stdc++.h>
using namespace std;
struct node {
	int v,w;
};
vector<node> g[1000010];
int c,n,m,d,q,top;
int w[500010],a[20010][20010];
bool f[500010];
long long ans[500010];
void dfs(int u) {
	for(int i=0; i<g[u].size(); i++) {
		int v=g[u][i].v,w=g[u][i].w;
		if(ans[u]+w<ans[v]) {
			ans[v]=ans[u]+w;
			dfs(v);
		}
	}

}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	top=m;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		int ss;
		cin>>ss;
		for(int j=1; j<=ss; j++) {
			int zt,tt;
			cin>>zt>>tt;
			++top;
			if(j!=1) {
				g[top].push_back((node) {
					top-1,0
				});
				g[top-1].push_back((node) {
					top,0
				});
//				cout<<top<<" "<<top-1<<" "<<0<<endl;
//				cout<<top-1<<" "<<top<<" "<<0<<endl;
			}
			g[top].push_back((node) {
				zt,tt
			});
			g[zt].push_back((node) {
				top,tt
			});
//			cout<<top<<" "<<zt<<" "<<tt<<endl;
//			cout<<zt<<" "<<top<<" "<<tt<<endl;
		}
	}
	memset(ans,0x3f,sizeof(ans));
	ans[1]=0;
	dfs(1);

//	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
//	cout<<endl;
	for(int i=1; i<=n; i++) {
		memset(ans,0x3f,sizeof(ans));
		ans[i]=0;
		dfs(i);
		for(int j=1;j<=top;j++) a[i][j]=ans[j];
	}
	for(int i=1; i<=q; i++) {
		int u,v;
		cin>>u>>v;
		cout<<a[u][v]+w[u]+w[v]<<endl;
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
