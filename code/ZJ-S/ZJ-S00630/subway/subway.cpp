#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010],kk;
struct node{
	int id;
	long long t;
};
vector<node>a[500010];
long long dp[555][555];
int x,y;
long long ans=1e10;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dp[i][j]=1e10;
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&kk);
		for(int j=1;j<=kk;j++){
			int aa,tt;
			scanf("%d%d",&aa,&tt);
			a[aa].push_back((node){i,tt});
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<a[k].size();i++){
			for(int j=0;j<a[k].size();j++){
				dp[a[k][j].id][a[k][i].id]=
				dp[a[k][i].id][a[k][j].id]=
				min(dp[a[k][i].id][a[k][j].id],a[k][j].t+a[k][i].t);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][i]=dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		ans=1e10;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,a[x][i].t+a[y][j].t+dp[a[x][i].id][a[y][j].id]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
