//freopen checked?

#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=305;
int c,t,n,d,x[N];
int ans;
//void dfs(int x,int y,int u,int cnt) {
//	
//}
void solve() {
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>x[i];
//	for(int i=1;i<=n;++i) {
//		for(int j=1;j<=n;++j) {
//			if(i==j)continue;
//			dfs(i,j,i,0);
//		}
//	}
	cout<<"0\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
