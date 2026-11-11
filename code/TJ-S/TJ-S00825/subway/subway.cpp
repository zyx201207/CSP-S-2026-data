#include<bits/stdc++.h>
using namespace std;
int zu[500005];
int t[505][500005];
long long g[505][505];
int n;
inline void solve(){
	int x,y;
	cin>>x>>y;
	vector<int>a;
	vector<int>b;
	for(int i=1;i<=n;i++){
		if(t[i][x]){
			a.push_back(i);
		}
		if(t[i][y]){
			b.push_back(i);
		}
	}
	long long cnt=1e18;
	for(auto u:a){
		for(auto v:b){
			long long k=g[u][v];
			k+=t[u][x];
			k+=t[v][y];
			cnt=min(cnt,k);
		}
	}
	cnt+=zu[x];
	cnt+=zu[y];
	cout<<cnt<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,m,d,q;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zu[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			t[i][x]=y;
		}
		for(int j=1;j<=n;j++){
			g[i][j]=1e18;
		}
		g[i][i]=0;
	}
	for(int j=1;j<=m;j++){
		vector<int>a;
		for(int i=1;i<=n;i++){
			if(t[i][j]){
				for(auto ti:a){
					long long p=t[i][j];
					p+=t[ti][j];
					g[i][ti]=min(g[i][ti],p);
					g[ti][i]=g[i][ti];
				}
				a.push_back(i);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				g[j][i]=g[i][j];
			}
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
//zsy
