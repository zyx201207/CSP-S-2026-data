#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,d;
int a[100010],f[100010];
int g[100010];
vector<int>e[100010];
bool vis[100010];
struct E{
	int x,y;
};
queue<E>q;
void bfs(int t){
	q.push(E{t,0});
	vis[t]=1;
	while(!q.empty()){
		int x=q.front().x;
		int k=q.front().y;
		q.pop();
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			if(vis[y]==0){
				vis[y]=1;
				f[y]=k+1;
				g[y]=1;
				q.push(E{y,k+1});
			}else if(vis[y]&&k+1==f[y]){
				g[y]++;
				q.push(E{y,k+1});
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			if(d>=2*(a[2]-a[1])&&d<3*(a[2]-a[1])){
				int ans=0;
				for(int i=1;i<=n;i++){
					ans=ans+(n-i)/3;
				}
				cout<<ans<<endl;
			}else cout<<0<<endl;
		}
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					e[i].push_back(j);
			//		e[j].push_back(i);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(f,0,sizeof(f));
			memset(g,0,sizeof(f));
			bfs(i);
			for(int j=1;j<=n;j++){
				if(g[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}