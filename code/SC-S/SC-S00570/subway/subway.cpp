#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =  405,M = 2e5+5;
int c,n,m,d,q;
ll w[M],k[N],a[N][M],t[N][M];
int st,ed;
vector<int> stop[M];
ll dis[N][N];
int sid[N][M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); //一定要删注释
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			sid[i][a[i][j]] = j;
			stop[a[i][j]].push_back(i);
		}
	}
	memset(dis,0x3f3f3f3f3f3f3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i] = 0;
	}
	
	for(int i=1;i<=m;i++){
		if(stop[i].size() >= 2){
			for(int l=0;l<int(stop[i].size());l++){
				for(int r=0;r<int(stop[i].size());r++){
					int l1 = stop[i][l],l2 = stop[i][r];
					if(r != l){
						dis[l2][l1] = min(dis[l2][l1],t[l1][sid[l1][i]] + t[l2][sid[l2][i]]);
						dis[l1][l2] = min(dis[l1][l2],t[l1][sid[l1][i]] + t[l2][sid[l2][i]]);
					}
				}
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			for(int f=1;f<=n;f++){
				if(l != r && (l != f && r != f)){
					dis[l][r] = min(dis[l][r],dis[l][f]+dis[f][r]);
					dis[r][l] = min(dis[l][r],dis[l][f]+dis[f][r]);
				}
			}
		}
	}
	ll ans = 0;
	while(q--){
		ans = 0;
		cin >> st >> ed;
		ans += w[st]+w[ed];
		ll ret = (ll)1e19;
		for(int i=0;i<int(stop[st].size());i++){
			int sl = stop[st][i];
			for(int j=0;j<int(stop[ed].size());j++){
				int el = stop[ed][j];
				ret = min(ret , dis[sl][el] + t[sl][sid[sl][st]] + t[el][sid[el][ed]]);
				//cout << ret << " " << dis[sl][el] << " " << t[sl][sid[sl][st]] << " " <<  t[el][sid[el][ed]] << "\n";
			}
			
		}
		cout << ans + ret << "\n";
	}
	return 0;
}