#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int c,n,m,d,q,w[N],b[505][N];
long long dis[505][505];
vector<int>H[N];
struct nnode{
	int k;
	vector<int>a,t;
}a[505];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].a.push_back(-1);
		a[i].t.push_back(-1);
		for(int j=1,x,y;j<=a[i].k;j++){
			cin>>x>>y;
			a[i].a.push_back(x);
			a[i].t.push_back(y);
			b[i][a[i].a[j]]=a[i].t[j];
			H[a[i].a[j]].push_back(i);
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<i<<':';
//		for(auto j:H[i]) cout<<j<<' ';
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j:H[i])
			for(int p:H[i]){
				if(j==p) continue;
				dis[p][j]=dis[j][p]=min(dis[p][j],(ll)b[j][i]+b[p][i]);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if(dis[i][j]==1e18) cout<<'-'<<" \n"[j==n];
//			else cout<<dis[i][j]<<" \n"[j==n];
	for(int x,y;q;q--){
		cin>>x>>y;
		ll ans=1e18;
		for(auto i:H[x]){
			for(auto j:H[y]){
				ans=min(ans,(ll)b[i][x]+b[j][y]+dis[i][j]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return;
}
int main(){
//	system("fc subway.out subway5.ans");
	freopen("subway.in","r",stdin);
//	freopen("subway5.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T=1;
//	cin>>T;
	for(;T;T--) solve();
	return 0;
}
