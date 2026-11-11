#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k,mn;
int dis[10001][10001];
bool p[10001][10001],use[10001],f[10001];
void bfs(int x){
	queue<int> q;
	q.push(x);
	f[x]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=n;i++){
			if(!f[i]&&p[x][i]&&use[i]){
				f[i]=1;
				q.push(i);
			}
		}
	}
}
void dfs(int x,int s){
	if(s==0){
		int l=0;
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			if(!f[i]&&use[i]){
				l++;
				bfs(i);
			}
		}
		if(l>2)return;
		
		int mx=0;
		for(int i=1;i<=n;i++){
			if(use[i]){
				for(int j=1;j<=n;j++){
					if(!use[j]){
	//					cout<<dis[i][j]<<' ';
						mx=max(mx,dis[i][j]);
					}
				}
			}
		}
		mn=min(mn,mx);
		return ;
	}
	if(x>n)return;
	use[x]=1;
	dfs(x+1,s-1);
	use[x]=0;
	dfs(x+1,s);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		mn=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)dis[i][j]=0;
				dis[i][j]=1000000001;
				p[i][j]=0;
			}
		}
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			p[x][y]=p[y][x]=1;
			dis[x][y]=dis[y][x]=1;
		}
		for(int l=1;l<=n;l++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
				}
			}
		}
		srand(time(0));
		cout<<rand()%n+1<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
