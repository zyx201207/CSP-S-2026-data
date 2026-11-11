#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int N=105;
vector<int> g[N];
bool vis[N],book[N];
int n,k;
int dist(int s){
	for(int i=1;i<=n;i++) vis[i]=0;
	queue<pair<int,int>> q;
	q.push({s,1});
	vis[s]=1;
	while(!q.empty()){
		int u=q.front().first,cnt=q.front().second; q.pop();
		if(book[u])
			return cnt;
		for(auto v:g[u])
			if(!vis[v]){
				vis[v]=1;
				q.push({v,cnt+1});
			}
	}
	return -1;
}
void lian(int u){
	for(auto v:g[u])
		if(!vis[v]&&book[v]){
			vis[v]=1;
			lian(v);
		}
}

int tot,ans;
void dfs(int r){
	if(r==n+1){
		if(tot!=k) return;
		
		for(int i=1;i<=n;i++) vis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]||!book[i]) continue;
			vis[i]=1,cnt++;
			if(cnt>2) break;
			lian(i);
		}
		if(cnt>2) return;
		
		int res=0;
		for(int i=1;i<=n;i++){
			if(book[i]) continue;
			res=max(res,dist(i));
		}
		ans=min(ans,res);
		return;
	}
	dfs(r+1);
	if(tot<k){
		book[r]=1,tot++;
		dfs(r+1);
		book[r]=0,tot--;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=0x3f3f3f3f;
		dfs(1);
		cout<<ans-1<<endl;
	}

	return 0;
}

