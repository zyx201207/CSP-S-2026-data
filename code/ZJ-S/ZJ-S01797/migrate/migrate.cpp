#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,ans=0;long long d,a[N];
int dis[5005][5005],sum[5005][5005];
vector<int>tree[5005];
void init(){
	for(int i=1;i<=n;i++){
		tree[i].clear();
		for(int j=1;j<=n;j++){
			dis[i][j]=0;sum[i][j]=0;
		}
	}
}
void bfs(int x){
	
	queue<int>q;
	q.push(x);
	dis[x][x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<tree[u].size();i++){
			int v=tree[u][i];
			if(dis[x][v]==0){
				dis[x][v]=dis[x][u]+1;
				q.push(v);
			}
		}
	}
}
void dfs(int hd,int x,int dep){
//	cout<<hd<<' '<<x<<' '<<dep<<endl;
	if(dep>dis[hd][x])return ;
	if(dep==dis[hd][x]&&hd!=x){
		sum[hd][x]++;
//		return ;
	}
	for(int i=0;i<tree[x].size();i++){
		int y=tree[x][i];
		dfs(hd,y,dep+1);
	}
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]>d)break;
					tree[i].push_back(j);
				}
			}
			ans=0;
			for(int i=1;i<=n;i++){
				bfs(i);
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					dis[i][j]--;
				}
			}
			for(int i=1;i<=n;i++){
				dfs(i,i,0);
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
//					cout<<sum[i][j]<<' ';
					if(sum[i][j]==2)ans++;
				}
//				cout<<endl;
			}
			cout<<ans<<'\n';
			init();
		}
		
		return 0;
	}

	
	return 0;
}
//0 1
//5 3
//-3 0 2 3 4
