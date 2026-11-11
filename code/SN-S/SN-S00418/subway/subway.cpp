#include <bits/stdc++.h>
#define int long long
#define pii pair <int,int>
#define fir first
#define sec second
#define inf 20000000000000
using namespace std;
int c,n,m,d,q;
vector <pii> to[500010];
int ent[500100];
int dp[510][510];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
	    cin >> ent[i];
	}
	for(int i = 1,k;i <= n;i++){
		cin >> k;
		for(int j = 1,x,y;j <= k;j++){
			cin >> x >> y;
			to[x].push_back({i,y});
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dp[i][j] = inf;
			if(i == j){
				dp[i][j] = 0;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		for(int j = 0;j < to[i].size();j++){
			for(int k = 0;k < to[i].size();k++){
				if(j == k) continue;
				int ya = to[i][j].fir,yb = to[i][k].fir;
				int va = to[i][j].sec,vb = to[i][k].sec;
				dp[ya][yb] = min(dp[ya][yb],va + vb); 
			}
		}
	}
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(dp[i][k] == inf || dp[k][j] == inf) continue;
				dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1,x,y;i <= q;i++){
	    cin >> x >> y;
	    int ans = inf;
		for(int j = 0;j < to[x].size();j++){
			for(int k = 0;k < to[y].size();k++){
				int ya = to[x][j].fir,yb = to[y][k].fir;
				int va = to[x][j].sec,vb = to[y][k].sec;
				ans = min(ans,va + vb + dp[ya][yb]);
			}
		}	
		cout << ent[x] + ent[y] + ans << endl;
	}
}
