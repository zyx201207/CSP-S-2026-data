#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pii pair<int,int>
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e2+5;
const int M = 5e5+5;
ll c, n, m, d, q;
ll dis[N][N];
ll w[M];
vector <int> con[M];
struct II{
	int s;
	ll t;
};
//vector <II> st[N];
vector <II> ti[M];
ll check(int x, int y){
	ll ans=INF;
	ll D1[501];
		for(auto it : ti[x]){
		D1[it.s]=it.t;
	}
	ll D2[501];
		for(auto it : ti[y]){
		D2[it.s]=it.t;
	}
	for(int j=0; j<con[x].size(); j++){
		for(int k=0; k<con[y].size(); k++){
			int u = con[x][j], v = con[y][k];
			ans=min(ans,dis[u][v]+D1[u]+D2[v]);
//			cout << ans <<"  "<<dis[j][k]<<con[x][j]<<con[y][k]<< endl;
		}
	}
	return ans;
}
void init(int x){
//	for(int i=1; i<=m; i++) con[i]=-1;
	for(int i=1; i<=x; i++){
		for(int j=1; j<=x; j++){
			if(i!=j)
			dis[i][j]=INF;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	init(n);
	for(int i=1; i<=m; i++) cin >> w[i];
	for(int i=1; i<=n; i++){
		int k;
		cin >> k;
		for(int j=1; j<=k; j++){
			int x, y;
			cin >> x >> y;
			ti[x].push_back({i,y});
			con[x].push_back(i);
		}
	}
	for(int i=1; i<=n; i++){
		if(con[i].size()>1){
			ll D[501]={};
			for(auto it : ti[i]){
				D[it.s]=it.t;
			}
			for(int j=0; j<con[i].size(); j++){
				for(int k=j+1; k<con[i].size(); k++){
					int u = con[i][j], v = con[i][k];
					
					dis[v][u]=min(dis[v][u],D[u]+D[v]);
					dis[u][v]=dis[v][u];
				}
			}
		}
	}
	for(int k=1; k<n; k++){
		for(int l=1; l<=n; l++){
			for(int r=1; r<=n; r++){
				dis[l][r]=min(dis[l][r],dis[l][k]+dis[k+1][r]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << check(x,y)+w[x]+w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
