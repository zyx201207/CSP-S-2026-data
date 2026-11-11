#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long m,w[N],n,o,idx,t,l=1,c,d,k[N],q,x,y,dp[N],wr[500][N*2],ne[500][2*N];
void add(int a,int b,int c){
	if(a!=l){
		l=a;
		idx=0;
	}
	wr[a][b]=c;
	ne[a][++idx]=b;
}
void dis(int u,int r){
	for(int p=1;p<=n;p++){
		int ln,nn;
		for(int i=1;i<=k[p];i++){
			if(ne[r][i]==u){
				if(i+1<=k[r]) nn=ne[r][i+1];
				if(i-1>0) ln=ne[r][i-1];
				break;
			}
		}
		if(p==r){
			if(dp[u]<dp[ln]){
				dp[u]=dp[ln];
				dis(ln,p);
			}
			if(dp[u]<dp[nn]){
				dp[u]=dp[nn];
				dis(nn,p);
			}
		}
		else{
			if(dp[u]+wr[r][ln]+wr[p][ln]<dp[ln]){
				dp[ln]=(wr[r][ln]+wr[p][ln]+dp[u]);
				dis(ln,p);
			}
			if(dp[u]+wr[r][nn]+wr[p][nn]<dp[nn]){
				dp[nn]=(dp[u]+wr[r][nn]+wr[p][nn]);
				dis(nn,p);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld%lld",o,t);
			add(i,o,t);
		}
	}
	for(int p=1;p<=q;p++){
		scanf("%lld%lld",&x,&y);
			dp[x]=w[x];
			dis(x,0);
			cout<<dp[y];
	}
	return 0;
}
//华风夏韵，洛水天依 
