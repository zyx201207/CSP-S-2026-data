#include<bits\stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int c,t,n;
ll d,a[maxn],dp[maxn][maxn],ans;
void bfs(int x){
	queue<int> q;
	ll dis[maxn];
	memset(dis,-1,sizeof dis);
	q.push(x);
	dis[x]=0;
	dp[x][x]=1;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=u+1;i<=n;i++){
			if(a[i]-a[u]>d){
				break;
			}
			else{
				if(dis[i]==-1||dis[i]>dis[u]+1){
					dis[i]=dis[u]+1;
					dp[x][i]=dp[x][u];
					q.push(i);
				}
				else if(dis[i]==dis[u]+1){
					dp[x][i]+=dp[x][u];
				}
			}
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(dp,0,sizeof dp);
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}