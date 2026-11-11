#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int c,n,m,d,q,dis[505][MAXN],w[MAXN];
vector <int> bel[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q; 
	for (int i=1;i<=m;i++) cin >> w[i];
	memset(dis,0x3f3f3f3f,sizeof(dis));
	for (int i=1;i<=n;i++){
		int k; cin >> k;
		for (int j=1;j<=k;j++){
			int a,t; cin >> a >> t;
			bel[a].push_back(i);
			dis[i][a+n]=t;
		}
	} 
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n+m;k++)
				dis[min(i,j)][max(i,j)] = min(dis[min(i,k)][max(i,k)]+dis[min(j,k)][max(j,k)],dis[min(i,j)][max(i,j)]);
	while (q--){
		int x,y,ans=1e18+5; cin >> x >> y;
		for (int i:bel[x]){
			for (int j:bel[y]){
				ans = min(ans,dis[min(i,j)][max(i,j)]+dis[i][x+n]+dis[j][y+n]);
			} 
		}
		ans += w[x]+w[y]; 
		cout << ans << endl;
	}
	return 0;
}
