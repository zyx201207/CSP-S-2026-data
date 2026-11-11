#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+6,M=1e3+3;
int c,t,n,k,d[M][M],fa[N],flag[N];
vector<int> e[N];
int getfa(int x){
	return fa[x]==x ? x : fa[x]=getfa(fa[x]);
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for (int v:e[u]){
			if (d[s][u]+1<d[s][v]){
				d[s][v]=d[s][u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for (int i=1;i<=n;i++){
			e[i].clear();
			for (int j=1;j<=n;j++){
				d[i][j]=(i==j?0:1e9);
			}
		}
		for (int i=1;i<n;i++){
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i=1;i<=n;i++) bfs(i);//计算每对点之间的距离 
		int ans=1e9;
		for (int mask=0;mask<(1<<n);mask++){
			int cnt=0,x=mask;
			vector<int> a;
			for (int i=0;i<n;i++){
				fa[i+1]=i+1;
				flag[i+1]=0; 
				if ((mask>>i)&1){
					a.push_back(i+1);
					flag[i+1]=1;
					cnt++;
				}
			}
			if (cnt!=k) continue;
			for (int x:a){
				for (int y:a){
					if (x>=y) continue;
					int fx=getfa(x),fy=getfa(y);
					if (d[x][y]==1){
						fa[fy]=fx;
					}
				}
			}
			cnt=0;
			for (int x:a) cnt+=(getfa(x)==x);
			if (cnt>2) continue;
			int maxx=-1;
			for (int i=1;i<=n;i++){
				if (flag[i]) continue;
				int minn=1e9;
				for (int x:a) minn=min(minn,d[i][x]); 
				maxx=max(maxx,minn);
			}
			ans=min(ans,maxx);
		}
		cout << ans << endl;
	}
	return 0;
} 
/*
17:45 开 T4
18:07 通过下方样例1&2，期望得分15pts 
总期望得分 15pts 
*/ 
