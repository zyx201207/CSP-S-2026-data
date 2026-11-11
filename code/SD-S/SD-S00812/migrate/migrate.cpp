#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
const int INF=1e9;
int C,T,n;
ll a[N],d,ans;
int R[N];
queue<int> q;
int dis[N],cnt[N];
bool vis[N];
void bfs(int s){
	for(int i=1;i<=n;i++) vis[i]=0,cnt[i]=0;
	q.push(s);
	vis[s]=1,dis[s]=0,cnt[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v=u+1;v<=R[u];v++){
			if(!vis[v]){
				dis[v]=dis[u]+1;
				vis[v]=1,cnt[v]=cnt[u];
				q.push(v);
			}else if(dis[v]==dis[u]+1) cnt[v]+=cnt[u];
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		int j=1;
		for(int i=1;i<=n;i++){
			while(j<n&&(a[j+1]-a[i])<=d) j++;
			R[i]=j;
		}
		for(int i=1;i<n;i++){
			bfs(i);
			for(int j=i+1;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<g[i][j]<<' '<<c[i][j]<<'\n';
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//AIR.
//Natukage.
