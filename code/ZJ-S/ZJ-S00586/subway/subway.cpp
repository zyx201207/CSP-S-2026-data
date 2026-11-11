#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int unsigned int
using namespace std;
const int N=5e3+5;
int c,n,m,d,q,k,w0[N],w1[505][N];
signed main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ioi;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) cin>>w0[i];
	if(n==1) {
		cin>>k;
		int zt[N],tm[N],s,e;
		for(int i=1; i<=k; i++) cin>>zt[i]>>tm[i];
		for(int i=1; i<=q; i++) {
			cin>>s>>e;
			cout<<w0[s]+tm[s]+tm[e]+w0[e];
		}
	} else {
		int xl[N];
		for(int i=1; i<=n; i++) {
			cin>>k;
			for(int j=1; j<=k; j++) {
				cin>>xl[j]>>w1[j];
			}
			for(int t1=1; t1<=k; t1++) {
				for(int t2=t1+1; t2<=k; t2++) {
					g[xl[t1]].push_back(xl[t2],i);
					g[xl[t2]].push_back(xl[t1],i);
				}
			}
		}
		for(int i=1; i<=q; i++){
			ans=0;
			memset(vis,false,sizeof(vis));
			cin>>s>>e;
			bfs(s,e);
		}
	}
	return 0;
}