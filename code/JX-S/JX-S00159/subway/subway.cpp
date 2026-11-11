#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
struct node{
	int a,t;
};
int ccccc;
int n,m,d,Q,ans;
int w[N],cnt[N],vis[N];
vector<node> li[N],ts[N];
void iiinput(){
	cin >> ccccc >> n >> m >> d >> Q;
	for(int i = 1 ; i <= m ; i ++) cin >> w[i];
	node zzhengxi,zzhengxi2;
	for(int i = 1,k ; i <= n ; i ++){
		cin >> k;
		for(int j = 1,a,t ; j <= k ; j ++){
			cin >> a >> t,cnt[a] ++;
			zzhengxi.a = a,zzhengxi.t = t;
			li[i].push_back(zzhengxi);
			zzhengxi2.a = i,zzhengxi2.t = t;
			ts[a].push_back(zzhengxi2);
		}
	}
}
queue<node> q;
void bfs(int x,int y){
	memset(vis,0,sizeof(vis));
	q.push({x,0});
	while(!q.empty()){
		int u = q.front().a,t = q.front().t;
		q.pop();
		vis[u] = 1;
		if(u == y){ans = t;return;}
		for(int i = 0 ; i < ts[u].size() ; i ++){
			int l = ts[u][i].a,idx;
			for(int j = 0 ; j < li[l].size() ; j ++)
				if(li[l][j].a == u){idx = j;break;}
			if(idx > 0 && !vis[ li[l][idx - 1].a ])
				q.push({li[l][idx - 1].a,t + li[l][idx - 1].t});
			if(idx <= li[l].size() - 2 && !vis[ li[l][idx + 1].a ])
				q.push({li[l][idx + 1].a,t + li[l][idx + 1].t});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	iiinput();
	while(Q --){
		int x,y; cin >> x >> y;
		ans = w[x] + w[y];
		bfs(x,y);
		cout << ans << '\n';
	}
	return 0;
}
//RP ++
//Luogu @zzhengxi
