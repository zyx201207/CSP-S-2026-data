#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int M = 505;
int c,n,m,d,q;
ll w[N],id[N],tot;
ll G[M][M];
struct node{
	ll idx,w;
}tmp;
vector<node> tr[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1,k;i <= n;i++){
		cin >> k;
		for (int j = 1,now;j <= k;j++){
			cin >> now >> tmp.w;
			tmp.idx = i;
			tr[now].push_back(tmp);
			id[now] = i;
		}
	}
	memset(G,0x3f,sizeof(G));
	for (int i = 1;i <= m;i++){
		if (tr[i].size() >= 2){
			for (int j = 0;j < (int)tr[i].size();j++){
				for (int k = 0;k < (int)tr[i].size();k++){
					if (j == k) continue;
					G[tr[i][j].idx][tr[i][k].idx] = min(G[tr[i][j].idx][tr[i][k].idx],tr[i][j].w + tr[i][k].w);
				}
			}
		}
	}
	for (int k = 1;k <= n;k++){
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= n;j++) G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
		}
	}
	for (int i = 1;i <= n;i++) G[i][i] = 0;
	while (q--){
		int x,y;
		cin >> x >> y;
		ll ans = w[x] + w[y];
		ll minn = LONG_LONG_MAX;
		for (int j = 0;j < (int)tr[x].size();j++){
			for (int k = 0;k < (int)tr[y].size();k++){
				minn = min(minn,G[tr[x][j].idx][tr[y][k].idx] + tr[x][j].w + tr[y][k].w);
			}
		}
		cout << ans + minn << '\n';
	}
}
