#include<bits/stdc++.h>//48pts£¬²»Òª¹Ò·Ö°¡
using namespace std;
typedef long long ll;
const int N=2000005;
vector<int> g[N];
int n;
ll d,x[N],dis[N],cnt[N],ans;
bool vis[N];
void init1(int n){
	ans=0;
	for(int i=1;i<=n;i++) g[i].clear();
}
void init2(int n){
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
		vis[i]=false;
		cnt[i]=1;
	}
}
void bfs(int st){
	init2(n);
	queue<int> q;
	q.push(st);
	dis[st]=0;
	vis[st]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
			if(!vis[v]){
				dis[v]=dis[u]+1;
				cnt[v]=cnt[u];
				q.push(v);
				vis[v]=true;
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		init1(n);
		for(int i=1;i<=n;i++) cin>>x[i];
		bool flag=true;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=x[2]-x[1]){
				flag=false;
				break;
			}
		}
		if(flag) cout<<n-d/(x[2]-x[1])*2+1<<"\n";
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[i]<=d){
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			for(int i=1;i<=n;i++){
				bfs(i);
				for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
