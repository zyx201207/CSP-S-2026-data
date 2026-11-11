#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	int u,v;
}edge[N];
map<int,int> vise;
int C,T,n,k,cs[N],ans,fa[N],dp[20][20];
int Find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=Find(fa[x]);
}
void dfs(int x,int m){
	if(x>n){
		if(m>0)	return ;
		for(int i=1;i<=n;i++){
			fa[i]=i;
			for(int j=1;j<=n;j++){
				dp[i][j]=0x3f3f3f3f;
				if(i==j)	dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			int u=edge[i].u,v=edge[i].v;
			if(cs[u]==1&&cs[v]==1){
				if(Find(u)!=Find(v)){
					fa[Find(u)]=Find(v);
				}
				
			}
			dp[u][v]=1;
			dp[v][u]=1;
		}
		int cnt=0;
		vise.clear();
		for(int i=1;i<=n;i++){
			if(cs[i]==1&&vise[Find(i)]==0){
				cnt++;
				vise[Find(i)]=1;
			}
		}
		if(cnt>2)	return ;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		int sum=-0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			int minn=0x3f3f3f3f;
			for(int j=1;j<=n;j++){
				//cout<<dp[i][j]<<' ';
				if(dp[i][j]==0x3f3f3f3f||i==j)	continue;
				if(cs[j])	minn=min(minn,dp[i][j]);
			}
			if(cs[i])	minn=0;
			sum=max(sum,minn);
			//cout<<'\n';
		}
		ans=min(ans,sum);
		return ;
	}
	if(m>0){
		cs[x]=1;
		dfs(x+1,m-1);
	}
	cs[x]=0;
	dfs(x+1,m);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		memset(edge,0,sizeof(edge));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>edge[i].u>>edge[i].v;
		}
		ans=0x3f3f3f3f;
		dfs(1,k);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
