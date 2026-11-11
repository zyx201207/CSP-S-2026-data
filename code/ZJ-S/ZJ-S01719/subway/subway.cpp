#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int k[510];
int tot;
vector<int> z[510];
set<int> zz[510];
vector<int> t[510];
int a[510][510];
long long ans;
int l,r;
int vis[510][510];
struct node{
	int x,y;
	long long cnt;
	bool operator<(const node &xx)const{
		return cnt>xx.cnt;
	}
};
void bfs(int x){
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push({x,l,t[x][a[x][l]]});
	while(!q.empty()){
		node u=q.top();
		q.pop();
		if(vis[u.x][u.y]){
			continue;
		}
		if(u.cnt>ans){
			return;
		}
		vis[u.x][u.y]=1;
		if(u.y==r){
			ans=min(ans,u.cnt+t[u.x][a[u.x][u.y]]);
			return;
		}
		if(a[u.x][u.y]!=k[u.x]){
			q.push({u.x,z[u.x][a[u.x][u.y]+1],u.cnt});
		}
		if(a[u.x][u.y]!=1){
			q.push({u.x,z[u.x][a[u.x][u.y]-1],u.cnt});
		}
		for(int i=1;i<=n;i++){
			if(zz[i].count(u.y)&&i!=x){
				q.push({i,u.y,u.cnt+t[u.x][a[u.x][u.y]]+t[i][a[i][u.y]]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		z[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i][x]=j;
			z[i].push_back(x);
			t[i].push_back(y);
			zz[i].insert(x);
		}
	}
	while(q--){
		ans=1e18;
		cin>>l>>r;
		for(int i=1;i<=n;i++){
			if(zz[i].count(l)){
				bfs(i);
			}
		}
		ans+=w[l];
		ans+=w[r];
		cout<<ans<<"\n";
	}
	return 0;
}