#include<bits/stdc++.h>
using namespace std;
const int N=5005;

int c,T,n;
long long d,x[N],ans,dis[N],cnt[N];
bool vis[N];
vector<int> g[N];

void clear(){
	for (int i=1;i<=n*5;i++)  g[i].clear();
	ans=0;
}

void bfs(int s){
	queue<int> que;
	que.push(s);
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	memset(cnt,0,sizeof(cnt));
	cnt[s]=1;
	memset(vis,false,sizeof(vis));
	while (!que.empty()){
		int u=que.front();
		que.pop();
		if (vis[u])  continue;
		vis[u]=true;
		for (auto v:g[u]){
			if (dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				que.push(v);
			}else if (dis[u]+1==dis[v])
				cnt[v]+=cnt[u];
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if (c<=10){
		while (T--){
			cin>>n>>d;
			clear();
			for (int i=1;i<=n;i++)  cin>>x[i];
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					if (x[j]-x[i]<=d)
						g[i].push_back(j);
				}
			}
			for (int i=1;i<=n;i++){
				bfs(i);
				for (int j=1;j<=n;j++){
					if (cnt[j]==2)  ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}