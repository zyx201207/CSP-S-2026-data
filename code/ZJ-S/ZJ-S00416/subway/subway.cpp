#include<bits/stdc++.h>
#define maxm 500009
#define maxn 509
#define N 599999
#define ll long long
#define pii pair<int,ll>
#define fi first
#define se second
using namespace std;
int cll,n,m,d,q;
int w[N],sk[509];
vector<pii>f[maxm];
ll dp[maxn][maxn];
ll read(){
	char ch=getchar();
	ll wz=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		wz=wz*10+(ch-48);
		ch=getchar();
	}
	return wz;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cll>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		cin>>sk[i];
		int A,T;
		for(int j=1;j<=sk[i];j++){
			A=read(),T=read();
			f[A].push_back({i,T});
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pii j:f[i])
			for(pii k:f[i]){
				dp[j.fi][k.fi]=min(dp[j.fi][k.fi],j.se+k.se);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ll res=1e18;
		for(pii i:f[x])
			for(pii j:f[y])
				res=min(res,dp[i.fi][j.fi]+i.se+j.se);
		cout<<res+w[x]+w[y]<<'\n';
	}
	return 0;
}
