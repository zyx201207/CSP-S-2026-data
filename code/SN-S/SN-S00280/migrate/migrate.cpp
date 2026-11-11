#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll c,t,n,d,ans;
ll x[N];
vector<ll>g[N];
ll vis[N];
int rote[5005][5005];
struct node{
	int u,dep;
};
queue<node>q;
void bfs(int idx){
	q.push({idx,1});
	while(!q.empty()){
		int u=q.front().u,depth=q.front().dep;q.pop();
		if(vis[u]==0)vis[u]=depth;
		else if(vis[u]==depth){
			if(abs(rote[u][idx])==idx||abs(rote[idx][u])==idx){
				if(rote[u][idx]==idx)ans--;
				//if(t<=4)printf("--->%d and %d, dep=%d\n",idx,u,depth);
				//if(t<=4)printf("last has delected\n");
				rote[u][idx]=-idx;
			}
			else 
			{
				ans++;
				rote[u][idx]=rote[idx][u]=idx;
				//if(t<=4)printf("%d and %d, dep=%d\n",idx,u,depth);
			}
		}
		if(vis[u]<depth)continue;
		
		for(auto to:g[u]){
			if(to<idx)continue;
			q.push({to,depth+1});
		}
	}
}
void clear(){
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!q.empty())q.pop();
	ans=0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		clear();
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			memset(vis,0,sizeof(rote));
			
		}
		memset(rote,0,sizeof(rote));
		cout<<ans<<'\n';
	}
	return 0;
}

