#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[2000006],dis[5005][5005],cnt[5005][5005],vis[50005];
int dij(int s){
	for(int i=1;i<=n;i++)dis[s][i]=1e18;
	queue<int>q;
	q.push(s);	
	dis[s][s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=1;v<=n;v++){
			if(v==u)continue;
			if(dis[s][v]==1e18&&abs(a[u]-a[v])<=d){
				dis[s][v]=dis[s][u]+1;
				q.push(v);
			}
		}
	}
}
int ct(int s){
	for(int i=1;i<=n;i++)cnt[s][i]=vis[i]=0;
	queue<int>q;
	q.push(s);
	cnt[s][s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=n;i++){
			if(u==i)continue;
			if(dis[s][i]==dis[s][u]+1&&abs(a[u]-a[i])<=d){
				cnt[s][i]+=cnt[s][u];
				if(vis[i]==0)q.push(i),vis[i]=1;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<=n;i++)ct(i);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
