#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5005;//attention!!!

int cas,T;
int n,D,x[N];
int d[N],cnt[N];
/*
n^2 ?
建出<=d的所有边
枚举u. bfs找出u到后面每个点的最短路径数量

bfs:d==-1||距离==d

哎不是,我 7~10 大样例呢？？？ 
running migrate6.in...
跑了几min,出来了 
*/

vector<int> g[N];

signed main() {
//	fc migrate.out migrate6.ans
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cas>>T;
	while(T--) {
		cin>>n>>D;
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(x[j]-x[i]<=D)g[i].push_back(j);
				else break;
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			memset(d,-1,sizeof d);
			memset(cnt,0,sizeof cnt);
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int u=q.front();
				q.pop();
				if(cnt[u]>=3)continue;//这可以拯救嘛 
				for(int v:g[u]) {
					if(d[v]==-1) {
						cnt[v]++;
						d[v]=d[u]+1;
						q.push(v);
					} else if(d[u]+1==d[v]) {
						cnt[v]++;
						q.push(v);
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
//					cout<<i<<' '<<j<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
		//clear!!!
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}

	return 0;
}
//Let shit down...
//How comfortable!
//15:59-16:19
//floor 2 toilet

