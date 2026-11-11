#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,v;
};
vector<node> a[500006];
long long c,n,m,d,q,w[500005],dp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long u,v;
			scanf("%lld%lld",&u,&v);
			a[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e16;
			if(i==j) dp[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
		  	for(int k=j+1;k<a[i].size();k++){
		  		dp[a[i][j].x][a[i][k].x]=min(a[i][j].v+a[i][k].v,dp[a[i][j].x][a[i][k].x]);
		  		dp[a[i][k].x][a[i][j].x]=min(a[i][j].v+a[i][k].v,dp[a[i][k].x][a[i][j].x]);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][k]+dp[k][j],dp[i][j]);
			}
		}
	}
	while(q--){
		long long x,y,ans=1e16;
		scanf("%lld%lld",&x,&y);
		for(int j=0;j<a[x].size();j++){
		  	for(int k=0;k<a[y].size();k++){
				  ans=min(a[x][j].v+a[y][k].v+dp[a[x][j].x][a[y][k].x],ans);
			}
		}
		long long hh=(ans+w[x]+w[y]);
		printf("%lld\n",hh);
	}
	return 0;
} 

