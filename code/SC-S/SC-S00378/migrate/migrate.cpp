#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
#define int long long
using namespace std;
const int N = 2e6+3,inf = 1e18;
int c,t;
int n,a[N],d,dist[N],cnt[N];
int bor[N],pos;
queue<int> q;
void bfs(int s){
	q.push(s);
	for(int j=s;j<=n;++j) dist[j] = inf,cnt[j] = 0;
	cnt[s] = 1;
	dist[s] = 0;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i=u;i<=bor[u];++i){
			if(dist[i] > dist[u]+1){
				dist[i] = dist[u]+1;
				cnt[i] = cnt[u];
				q.push(i);  //
			}else if(dist[i] == dist[u]+1){
				cnt[i] += cnt[u];
			}
		}
	}
}
int get(int n,int d,int dat){
	if(d <= 2*dat-1) return 0;
	return max(0ll,n-1 - (d/dat-1)*2);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;++i) cin >> a[i];
		if(c >= 11 && c <= 12){
			cout << get(n,d,a[2]-a[1]) << "\n";
			continue;
		}
		pos = n;
		bor[n] = n;
		for(int i=n-1;i>=1;--i){  
			while(a[pos] > a[i] && a[pos]-a[i] > d){ 
				--pos;
			}
			bor[i] = pos;
		}
		int res = 0;
		for(int i=1;i<=n;++i){
			bfs(i);
			int re = 0;
			for(int j=i;j<=n;++j) re += (cnt[j]==2);
//			cout << i << ": \n";
//			for(int j=i;j<=n;++j) cout << dist[j] << " ";
//			cout << "\n";
			res += re;
		}
		cout << res << "\n";
//		cout << n << " " << d << " " << a[2]-a[1] <<" " <<res << " " <<get(n,d,a[2]-a[1]) << "\n";
	}
	return 0;
}
/*
0 5
5 1
1 2 3 4 5
5 2
1 2 3 4 5
5 3
1 2 3 4 5
5 4
1 2 3 4 5
5 5
1 2 3 4 5
*/