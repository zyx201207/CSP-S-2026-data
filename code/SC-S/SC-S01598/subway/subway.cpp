#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=505+10,M=5e5+10;
const ll INF=1e18;
int c,n,m,d,q;
ll w[M];
struct A{
	int id;ll tim;
};
vector <A> st[M];
ll f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1,k;i<=n;i++){
		cin >> k;
		for (int j=1,a,t;j<=k;j++){
			cin >> a >> t;
			st[a].push_back({i,t});
		}
	}
	memset(f,0x3f,sizeof f);
	for (int i=1;i<=m;i++){
		for (int s=0;s<(int)st[i].size();s++){
			for (int t=s+1;t<st[i].size();t++){
				int u=st[i][s].id,v=st[i][t].id;
				f[u][v]=min(f[u][v],st[i][s].tim+st[i][t].tim);
				f[v][u]=min(f[v][u],st[i][s].tim+st[i][t].tim);
			}
		}
	}
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++){
//			cout << f[i][j] << ' ';
//		}
//		cout << endl;
//	}
	for (int i=1,u,v;i<=q;i++){
		cin >> u >> v;
		ll minn=INF;
		for (int s=0;s<st[u].size();s++){
			for (int t=0;t<st[v].size();t++){
				int x=st[u][s].id,y=st[v][t].id;
				minn=min(minn,f[x][y]+st[u][s].tim+st[v][t].tim);
			}
		}
		cout << minn+w[u]+w[v] << '\n';
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