#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int M = 5e5+5;
long long w[M];
vector<pair<int,long long>>to[M];
long long mp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		scanf("%lld",w+i);
	}
	for(int i = 1;i <= n;i++){
		int k;scanf("%d",&k);
		for(int j = 1;j <= k;j++){
			int plat;long long t;
			scanf("%d%lld",&plat,&t);
			to[plat].push_back({i,t});
			for(size_t k = 0;k < to[plat].size()-1;k++){
				int lnew = to[plat][k].first;
				mp[i][lnew] = mp[lnew][i] = min(mp[i][lnew],to[plat][k].second + t);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		mp[i][i] = 0;
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				mp[i][j] = mp[j][i] = min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		long long ans = 1e18;
		scanf("%d%d",&x,&y);
		for(pair<int,long long> l : to[x]){
			for(pair<int,long long> r : to[y]){
				ans = min(mp[l.first][r.first]+l.second+r.second,ans);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}