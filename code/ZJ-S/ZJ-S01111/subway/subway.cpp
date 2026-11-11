#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510,M = 20010;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],ans;
bool f[N];
void dfs(int x,int T,int en){
	if(x == en){
		ans = min(ans,T);
		return;
	}
	for(int i = 1;i <= n;i++){
		if(f[i])
			continue;
		bool flag = false;
		for(int j = 1;j <= k[i];j++){
			if(a[i][j] == x){
				flag = true;
				continue;
			}
			if(!flag)
				continue;
			f[i] = true;
			dfs(a[i][j],T + t[i][x] + t[i][j],en);
			f[i] = false;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int i = 1,x,y;i <= q;i++){
		cin >> x >> y;
		ans = LLONG_MAX;
		dfs(x,0,y);
		cout << w[x] + ans + w[y] << "\n";
	}
	return 0;
}