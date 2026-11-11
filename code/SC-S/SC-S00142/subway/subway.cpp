#include<bits/stdc++.h>
#define int long long 
#define siz(x) ((int)(x.size()))
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int N=5e5+10;
const int M=5e2+10;

int n,m,q;
int w[N],len[N];
int f[M][M]; // 第 i 个站厅到第 j 个站厅的最小距离
vector<pii> bel[N]; // bel[i] ：第 i 个数，位于哪条地铁线，转乘的时间
vector<int> a[N],t[N];
void init() {
	rep(i,1,m) cin>>w[i];
	rep(i,1,n) {
		cin>>len[i];
		a[i].resize(len[i]+1),t[i].resize(len[i]+1);
		rep(j,1,len[i]) {
			cin>>a[i][j]>>t[i][j];
			bel[a[i][j]].eb(i,t[i][j]);
		}
	}
	rep(i,1,n) rep(j,i+1,n) f[i][j]=f[j][i]=1e17;
	rep(i,1,m) {
		int len=bel[i].size();
		rep(j,0,len-1) rep(k,j+1,len-1) {
			int u=bel[i][j].first,v=bel[i][k].first;
			f[u][v]=min(f[u][v],bel[i][j].second+bel[i][k].second);
			f[v][u]=min(f[v][u],bel[i][j].second+bel[i][k].second);
		}
	}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) if (i!=j and j!=k and i!=k) {
		if (f[i][k]>=1e17 or f[k][j]>=1e17) continue;
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	} 
	return ;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,d;cin>>c>>n>>m>>d>>q;
	init();
	while (q--) {
		int x,y;cin>>x>>y;
		int res=1e17;
		for (auto [a,b] : bel[x]) for (auto [c,d] : bel[y]) res=min(res,f[a][c]+b+d);
		cout<<(res+w[x]+w[y])<<endl;
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