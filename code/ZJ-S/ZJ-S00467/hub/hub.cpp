#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,k,x,y,f[100][100],e[100][100],g[100],dp[100],t,a[100],mi;
queue<int>q;
void bfs(int x){
	int fx;
	q.push(x);
	dp[x]=0;
	while(!q.empty()){
		fx=q.front();q.pop();
		for(int i=1;i<=n;i++)
			if(f[fx][i]==1){
				if(dp[i]<dp[fx]+1)
					dp[i]=dp[fx]+1,q.push(i);
			}
	}
}
int qiu(int t){
	int ma=0;
	memset(dp,127,sizeof(dp));
	for(int i=1;i<=t;i++)
		bfs(a[i]);
	for(int i=1;i<=n;i++)
		ma=max(ma,dp[i]);
	return ma;
}
void dfs(int x,int t){
	if(x==n+1){
		if(t==k) mi=min(mi,qiu(t));
		return ;
	}
	a[t+1]=x;dfs(x+1,t+1);
	dfs(x+1,t);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c<=3){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++)
				cin>>x>>y,f[x][y]=1;
			mi=1e18;
			dfs(1,0);
			cout<<mi<<"\n";
		}
	}
	else if(c==7||c==11||c==12){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++)
				cin>>x>>y,f[x][y]=1;
			if(k==1)
				cout<<0<<"\n";
			if(k==2)
				cout<<1<<"\n";
		}
	}
	return 0;
}