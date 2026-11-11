#include <bits/stdc++.h>
using namespace std;
const int N=2000005;

int c,T;
int n,k;
vector <int> g[N];
bool vis[N];
int dis[N];

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin>>c>>T;
	while(T--){
		int ans=0x7fffffff;
		cin>>n>>k;
		for(int i=0;i<N;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=0;i<(1<<n);i++){
			int now=i,cnt=0;
			memset(dis,127,sizeof(dis));
			memset(vis,0,sizeof(vis));
			for(int j=1;now;now>>=1,j++){
				if(now&1)
					dis[j]=0,cnt++;
			}
			if(cnt!=k)continue;
			queue <int> q;
			for(int i=1;i<=n;i++)
				if(!dis[i])q.push(i);
			while(!q.empty()){
				int k=q.front();q.pop();
				if(vis[k])continue;
				vis[k]=1;
				for(int _:g[k])
					if(!vis[_])dis[_]=dis[k]+1,q.push(_);
			}
			int ans_=0;
			for(int k=1;k<=n;k++)
				ans_=max(ans_,dis[k]);
			ans=min(ans,ans_);
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
