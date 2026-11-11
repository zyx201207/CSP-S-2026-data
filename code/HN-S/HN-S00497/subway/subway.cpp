#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=500010;
typedef long long ll;
#define endl '\n'

int a,b,n,m,q,w1[M];
vector<int> d[M],w2[N]; 
set<int> c[N];
ll f[N][N];

inline void work(){
	int x,y;
	cin >> x >> y;
	vector<int> c1,c2;
	for (int i=1;i<=n;i++){
		if (c[i].find(x)!=c[i].end() && c[i].find(y)!=c[i].end()){
			cout << 1ll*(w1[x]+w1[y]+w2[i][x]+w2[i][y]) << '\n';
			return ;
		}
		if (c[i].find(x)!=c[i].end())
			c1.push_back(i);
		if (c[i].find(y)!=c[i].end())
			c2.push_back(i);
	}
	ll ans=LLONG_MAX;
	int id1,id2;
	for (auto y:c1)
		for (auto z:c2)
			if (f[y][z]<ans){
				ans=f[y][z];
				id1=y,id2=z;
			}
	ans+=w1[x]+w1[y]+w2[id1][x]+w2[id2][y];
	cout << ans << '\n';
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> a >> n >> m >> b >> q;
	for (int i=1;i<=m;i++)
		cin >> w1[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=LLONG_MAX;
	for (int i=1;i<=n;i++)
		f[i][i]=0;
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
		w2[i].resize(M);
		for (int j=1;j<=k;j++){
			int y,z;
			cin >> y >> z;
			c[i].insert(y);
			w2[i][y]=z;
			d[y].push_back(i);
		}
	}
	for (register int i=1;i<=m;i++)
		for (auto y:d[i])
			for (auto z:d[i])
				if (y!=z)
					f[y][z]=f[z][y]=w2[y][i]+w2[z][i];
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (f[i][k]<LLONG_MAX && f[k][j]<LLONG_MAX)
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (int i=1;i<=q;i++) work();
	return 0;
}

