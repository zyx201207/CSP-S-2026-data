#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=5e5+1;
struct line {
	int s;
	ll t;
};
int c,n,m,d,q,deg[maxn],a[maxn][21],dis[401][401];
ll w[maxn];
vector<line> l[501];
void dfs(int x,int dep) {
	
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		l[i].push_back({k,0});
		for(int j=1;j<=k;j++) {
			int a;
			ll b;
			cin>>a>>b;
			l[i].push_back({a,b});
		}
	}
	if(!c||c>=7&&c<=11) {
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=m;i++) {
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++) {
			if(l[i][0].s==1) {
				continue;
			}
			int u=l[i][1].s,v=l[i][2].s;
			ll p=l[i][1].t,q=l[i][2].t;
			dis[u][v]=dis[v][u]=p+q;
		}
		for(int k=1;k<=m;k++) {
			for(int i=1;i<=m;i++) {
				for(int j=1;j<i;j++) {
					if(k==i||k==j||i==j) {
						continue;
					}
					dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++) {
		cout<<w[i]<<'\n';
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+dis[x][y]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
