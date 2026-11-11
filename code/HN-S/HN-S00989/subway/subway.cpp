#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+505;
int c,n,m,d,q,k,x,y,tot;
int a[N];
bool f[N];
int sum[N];
vector<array<int,2> > id[N];
int ans[505][505];
vector<array<int,2> > g[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	tot=m;
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=n;i++){
		ans[i][i]=0;
		++tot;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			id[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(auto j:id[i]){
			for(auto k:id[i]){
				ans[j[0]][k[0]]=min(ans[j[0]][k[0]],j[1]+k[1]); 
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<ans[i][j]<<" "; 
//		}
//		cout<<"\n"; 
//	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int tans=1e18;
		for(auto j:id[x]){
			for(auto k:id[y]){
				tans=min(tans,ans[j[0]][k[0]]+a[x]+a[y]+j[1]+k[1]);
			}
		}
		cout<<tans<<"\n";
	}
	return 0;
} 
