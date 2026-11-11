#include<bits/stdc++.h>
#define int long long
#define mid ((nl+nr)>>1)
#define f1 first
#define s2 second
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int C,t,n,d,c[5005][5005],x[5005],v[5005],dis[5005];
queue<int>q;
void bfs(int s){
	for(int i=1;i<=n;i++) v[i]=0,dis[i]=inf;
	q.push(s);
	dis[s]=0;
	c[s][s]=1;
	while(!q.empty()){
		int y=q.front();
		q.pop();
		if(v[y]) continue;
		v[y]=1;
		for(int i=y+1;i<=n&&x[i]<=x[y]+d;i++){
			if(v[i]) continue;
			if(dis[i]>dis[y]+1){
				c[s][i]+=c[s][y];
				dis[i]=dis[y]+1;
				q.push(i);
			}else if(dis[i]==dis[y]+1) c[s][i]+=c[s][y];
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<n;i++){
		bfs(i);
//		if(i==1) cout<<dis[5];
	}
	int ans=0;
//	cout<<c[1][7];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(c[i][j]==2) ans++;
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--) solve();
	return 0;
}
