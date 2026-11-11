#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,f[1001][1001],ts[500001],s,p,dp[1001][1001],l,r,q1,q2,q3,q4,ms;
struct node{
	int v,w;	
};
vector<node> lps[100001];
void dfs(int x,int fa,int ed,int sum){
	if(x==ed){
		ms=sum;
		return ;
	}
	for(int i=0;i<lps[x].size();i++){
		int y=lps[x][i].v;
		if(y!=fa){
			dfs(y,x,ed,sum+lps[x][i].w);
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m<=400){
	for(int i=1;i<=m;i++){
		cin>>ts[i];
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			f[i][j]=1e9;
			dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&s,&p);
			f[s][i]=p;
		}
	}
	for(int i=1;i<=m;i++) dp[i][i]=0; 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],f[i][k]+f[j][k]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		printf("%d\n",dp[l][r]+ts[l]+ts[r]);
	}
	return 0;
}
	for(int i=1;i<=m;i++){
		cin>>ts[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k>>q1>>q2>>q3>>q4;
		lps[q1].push_back({q3,q2+q4});
		lps[q3].push_back({q1,q2+q4});
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		ms=0;
		dfs(l,-100,r,0);
		//cout<<ms+ts[l]+ts[r]<<endl;
		printf("%d\n",ms+ts[l]+ts[r]);
	}
	return 0;
} 
