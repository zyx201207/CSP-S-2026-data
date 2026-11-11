#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,inf=1e9;
int x[N],r[N],dis[N],dp[N];
void bfs(int i){
	queue<int>q;
	q.push(i);dp[i]=1;dis[i]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=r[u];v>u;v--){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				dp[v]=dp[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)dp[v]+=dp[u];
			else break;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int c,T;cin>>c>>T;
	while(T--){
		int n,d,ans=0;cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		r[0]=1;
		for(int i=1;i<=n;i++){
			r[i]=r[i-1];
			while(x[r[i]+1]-x[i]<=d&&r[i]<n)r[i]++;
		}
		if(c>10&&c<12){
			int h=r[1]-1;
			if(h<=1)cout<<0<<"\n";
			else cout<<(n-h*2+1>0?n-h*2+1:0)<<"\n";
			continue;
		}
		if(c>12){
			for(int i=1;i<=n-2;i++){
				int t=r[i+1]-r[i];
				ans+=t;
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++)dis[j]=inf,dp[j]=0;
			bfs(i);
			for(int j=i;j<=n;j++)if(dp[j]==2)ans++;
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++)r[i]=0;
	}	
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/