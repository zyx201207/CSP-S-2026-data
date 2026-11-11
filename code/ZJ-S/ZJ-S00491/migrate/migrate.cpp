#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int x[N];
vector<int>e[N];
int vis[N];
inline int dfs(int u,int ed,int deep,int ans){
//	cout<<u<<" ";
	if(deep>ans)return 0;
	if(u==ed&&deep==ans){
		return 1;
	}
	int cnt=0;
	for(auto i:e[u])cnt+=dfs(i,ed,deep+1,ans);
	return cnt;
}
inline int bfs(int st,int ed){
	memset(vis,-1,sizeof(vis));
	queue<int>q;
	q.push(st);
	vis[st]=0;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==ed)return vis[ed];
		for(auto i:e[top]){
			if(vis[i]==-1){
				q.push(i);
				vis[i]=vis[top]+1;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d)break;
				e[i].push_back(j);
			}
		}
//		for(int i=1;i<=n;i++){
//			for(auto j:e[i])cout<<i<<" "<<j<<"  ";
//			cout<<"\n";
//		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans=bfs(i,j);
//				cout<<i<<" "<<j<<" "<<ans;
				int y=dfs(i,j,0,ans);
				if(y==2){
//					cout<<ans<<" "<<i<<" "<<j<<"\n";
					cnt++;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
