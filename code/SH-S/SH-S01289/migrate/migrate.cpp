# include <iostream>
# include <vector>
# include <cmath>
# include <algorithm>
# include <cstdio>
# include <cstring>
# define ll long long
# define MAXN 2000010
using namespace std;
int c, t;
int n, ans;
ll d;
ll x[MAXN];
vector<ll> G[MAXN];
int a[MAXN];
int minx[MAXN]; 

void find(int now, ll cnt) {
	cnt++;
	bool is_h = 0;
	if(minx[now] >= cnt){
		a[cnt]++;
		minx[now] = cnt;
	}
	for(int k : G[now]) {
		//cout<<cnt<<"\n";
		//cout<<now<<"->"<<k<<"\n";
		find(k,cnt);
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1; i <= t; i++) {
		memset(G,0,sizeof(G));
		memset(x,0,sizeof(x));
		memset(a,0,sizeof(a));
		memset(minx,0x7f,sizeof(minx));
		ans = 0;
		cin>>n>>d;
		for(int j = 1; j <= n; j++) cin>>x[j];
		for(int j = 1; j < n; j++) {
			//G[j].push_back(j + 1);
			for(int k = j + 1; k <= n; k++) {
				if(abs(x[j] - x[k]) <= d) {
					G[j].push_back(k);
				}
			}
		}
		find(1,0);
		for(int j = 1; j <= n; j++){
			//cout<<a[j]<<" ";
			if(a[j] == 2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0
1
*/
