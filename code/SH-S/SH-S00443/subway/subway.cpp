#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pir;
const ll inf=LLONG_MAX;
int n,m,c,d,q,k[500005],a[505][500005];
ll t[505][200005],w[500005],dis[2005][2005];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			dis[a[i][j]][m+i]=t[i][j];
			dis[m+i][a[i][j]]=t[i][j];
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			if(dis[i][k]!=inf){
				for(int j=1;j<=n+m;j++){
					if(dis[k][j]!=inf){
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
}
