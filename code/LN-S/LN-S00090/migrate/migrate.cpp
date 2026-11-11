#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[5005],ans;
int dis[5005],cnt[5005];
void dfs(int s,int u,int len){
	if(len==dis[u])
		cnt[u]++;
	dis[u]=min(dis[u],len);
	for(int i=u+1;i<=n;i++)
		if(x[i]-x[u]<=d)
			dfs(s,i,len+1);
	return;
}
signed _main(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		//dis[i][i]=0;
	}/*
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			if(x[j]-x[i]<=d)
				dis[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][k]=min(dis[i][j],dis[i][k]+dis[k][j]);*/
	for(int i=1;i<n;i++){
		memset(dis,0x3f,sizeof(dis));
		dfs(i,i,0);
		memset(cnt,0,sizeof(cnt));
		//dis[1][4]=2;
		dfs(i,i,0);
		//cout<<dis[1][4]<<'\n';
		for(int j=i+1;j<=n;j++)
			if(cnt[j]==2){
				//cout<<i<<' '<<j<<'\n';
				ans++;
			}
	}
	cout<<ans<<'\n';
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)_main();
	return 0;
}
