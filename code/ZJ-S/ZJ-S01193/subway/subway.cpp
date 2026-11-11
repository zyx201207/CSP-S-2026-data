#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+ch-48,ch=getchar();
	return ret*f;
}
const ll maxn=505,maxm=5e5+5,INF=1e18;
ll c,n,m,d,Q;
struct note{
	int to;ll val;
};
ll v[maxm],dp[maxn][maxn];
vector <note> q[maxm];
inline ll min(ll x,ll y){return x>y?y:x;}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();Q=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=INF;
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++)v[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			q[a].push_back({i,t});
		}
	}
	for(int u=1;u<=m;u++)
	for(int i=0;i<q[u].size()-1;i++)
	for(int j=i+1;j<q[u].size();j++)
	dp[q[u][i].to][q[u][j].to]=dp[q[u][j].to][q[u][i].to]=min(dp[q[u][i].to][q[u][j].to],q[u][i].val+q[u][j].val);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
	for(int i=1;i<=Q;i++){
		int l=read(),r=read();
		ll res=INF;
		for(int i=0;i<q[l].size();i++){
			for(int j=0;j<q[r].size();j++){
				res=min(res,q[l][i].val+q[r][j].val+dp[q[l][i].to][q[r][j].to]);
			}
		}
		printf("%lld\n",res+v[l]+v[r]);
	}
	return 0;
}