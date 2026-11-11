#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,Q;
int w[500005],a[505][500005],t,x[100005],y[100005],k[505],minx;
int flag[500005];
int cnt[505][500005];
void dfs(int pos,int time,int line,int goal){
	if(flag) return;
	if(pos == goal){
		minx = min(minx,time);
		return;
	}
	flag[pos] = 1;
	for(int i = 1;i <= n;i++){
		if(cnt[i][pos] and i != line){
			dfs(pos,time + cnt[line][pos] + cnt[i][pos],i,goal);
		}
	}
	for(int i = 1;i <= m;i++){
		if(cnt[line][i] and i != pos){
			dfs(i,time,line,goal);
		}
	} 
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//XX X XXX
	//OO O OOO
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t;
			cnt[i][a[i][j]] = t;//第i条线这个站对应的步行时间 
		}
	}
	for(int i = 1;i <= Q;i++){
		cin >> x[i] >> y[i];
	}
	int i = 1;
	while(Q--){
		memset(flag,0,sizeof(flag));
		minx = 1e18;
		dfs(x[i],0,0,y[i]);
		cout << minx << endl;
	}
	return 0;
} 
