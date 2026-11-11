#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 600;
const int maxm = 1e3+10;
int c,n,m,d,q,k;
ll w[maxm];
ll dis[maxm*2][maxm*2];
void floyd(){
	for (int k = 1;k<=m+n;k++){
		for (int i=1;i<=m+n;i++){
			for (int j=1;j<=m+n;j++){
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	//cout<<c<<"\n"; 
	//cout<<1<<"\n";
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	int u,v,we;
	memset(dis,0x3f3f3f,sizeof(dis));
	//cout<<1<<"\n";
	for (int i=1;i<=n;i++){
		cin>>k;
		for (int j=1;j<=k;j++){
			cin>>v>>we;
			dis[i+m][v] = we;
			dis[v][i+m] = we;
		}
	}
	//cout<<1<<"\n";
	/*for (int i=1;i<=m;i++){
		for (int j=m+1;j<=m*2;j++){
			cout<<dis[i][j]<<" ";
		} 
		cout<<"\n";
	} */
	//for 
	floyd();
	for (int i=1;i<=q;i++){
		cin>>u>>v;
		ll ans = dis[u][v]+w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
