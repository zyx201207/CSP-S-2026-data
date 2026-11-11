#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int M=5e5+5;
int C,n,m,d,q;
int a[M];
int f[N][N];
vector<pair<int,int> > vt[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,k,x,w;i<=m;i++){
		cin>>k;
		while(k--){
			cin>>x>>w;
			vt[x].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) f[i][j]=1e18*(i!=j);
	for(int i=1;i<=n;i++) for(auto u:vt[i]) for(auto v:vt[i]) if(f[u.first][v.first]>u.second+v.second) f[u.first][v.first]=u.second+v.second;
	for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) if(f[i][k]+f[k][j]<f[i][j]) f[i][j]=f[i][k]+f[k][j];
	for(int i=1,x,y,ans;i<=q;i++){
		cin>>x>>y;
		ans=1e18;
		for(auto u:vt[x]) for(auto v:vt[y]) if(f[u.first][v.first]+u.second+v.second<ans) ans=f[u.first][v.first]+u.second+v.second;
		cout<<ans+a[x]+a[y]<<"\n";
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
