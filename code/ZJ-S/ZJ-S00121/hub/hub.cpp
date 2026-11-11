#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=1e9;
vector<int>e[1000001];
bool p[1000001],vis[1000001];
struct node{
	int id,d;
};
void dfs(int x,int cnt){
	if(x>n){
		if(cnt!=k)return;
		memset(vis,0,sizeof(vis));
		int cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(p[i]&&!vis[i]){
				vis[i]=1;
				cnt3++;
				cnt2++;
				if(cnt3<=2){
					queue<int>q;
					q.push(i);
					while(!q.empty()){
						int s=q.front();
						q.pop();
						for(auto j:e[s]){
							if(!vis[j]&&p[j]){
								q.push(j);
								vis[j]=1;
							}
						}
					}
				}else return;
			}
		}
		int res=0;
		memset(vis,0,sizeof(vis));
		queue<node>q;
		for(int i=1;i<=n;i++){
			if(p[i]){
				q.push({i,0});
				vis[i]=1;
			}
		}
		while(!q.empty()){
			node s=q.front();
			res=max(res,s.d);
			q.pop();
			for(auto j:e[s.id]){
				if(!vis[j]){
					q.push({j,s.d+1});
					vis[j]=1;
					
				}
			}
		}
		ans=min(ans,res);
		return ;
	}
	if(cnt>k)return;
	if(n-x+1<k-cnt)return;
	dfs(x+1,cnt);
	p[x]=1;
	dfs(x+1,cnt+1);
	p[x]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
}/*0 2
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
 9 10*/
