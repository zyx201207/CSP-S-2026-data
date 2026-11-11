#include <bits/stdc++.h>
using namespace std;
long long c,n,m,md,q,w[1005],dis[500005],dt[501005],dx[1005][105],d[1005][505],db[1005],cnt,sy[500005],vis[500005];
struct node{
	long long to,c;
};
vector<node>v[500005];
struct node2{
	long long d,c;
};
bool operator <(node2 a,node2 b){
	return a.c > b.c; 
}
priority_queue<node2>dl;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> md >> q;
	cnt = m;
	for(long long i = 1;i <= m;i++) cin >> w[i];
	for(long long i = 1;i <= n;i++){
		long long k;
		cin >> k;
		for(long long j = 1;j <= k;j++){
			long long sc;
			cin >> dx[i][j] >> sc;
			if(db[dx[i][j]] > 0){
				cnt++;
				d[dx[i][j]][++db[dx[i][j]]] = cnt;
			}
			else d[dx[i][j]][++db[dx[i][j]]] = dx[i][j];
			dt[d[dx[i][j]][db[dx[i][j]]]] = sc;
			sy[dt[d[dx[i][j]][db[dx[i][j]]]]] = dx[i][j];
		}
		for(long long j = 1;j <= k;j++){
			for(long long o = j+1;o <= k;o++){
				v[dx[i][j]].push_back((node){dx[i][o],0});
			}
		}
	}
	for(long long i = 1;i <= m;i++){
		for(long long j = 1;j <= db[i];j++){
			for(long long o = 1;o <= db[i];o++){
				if(j == o) continue;
				v[d[i][j]].push_back((node){d[i][o],dt[d[i][j]]+dt[d[i][o]]});
			}
		}
	}
	while(q--){
		long long l,r,ans = 1e18;
		cin >> l >> r;
		for(long long i = 1;i <= db[l];i++){
			long long nw = d[l][i];
			memset(vis,0,sizeof vis);
			memset(dis,0x3f,sizeof dis);
			dl.push((node2){d[l][i],0});
			while(!dl.empty()){
				long long d = dl.top().d,c = dl.top().c;
				vis[d] = 1;
				dl.pop();
				if(sy[d] == r){
					ans = min(ans,dis[d]);
					continue;
				}
				for(long long i = 0;i < v[d].size();i++){
					long long to = v[d][i].to,cc = v[d][i].c;
					if(vis[to] || dis[to] <= dis[d]+cc) continue;
					dis[to] = dis[d]+cc;
					dl.push((node2){to,dis[to]});
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;		
}
	
	
