#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
void read(int &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
void read(ll &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SHEEP{
	const int N=505,M=5e5+5;
	const ll inf=0x3f3f3f3f3f3f3f3f;
	int c,n,m,d,q,w[M];ll dp[N][N];
	vector<pii> p[M];
	void _min(ll &a,ll b){
		if(a>b) a=b;
	}
	void work(){
		read(c);read(n);read(m);read(d);read(q);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=(i!=j)*inf;
		for(int i=1;i<=m;i++) read(w[i]);
		for(int i=1,k;i<=n;i++){
			read(k);
			for(int j=1,x,y;j<=k;j++){
				read(x);read(y);
				for(auto t:p[x]) _min(dp[i][t.fi],t.se+y);
				p[x].emplace_back(i,y);
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[j][i]);
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
		for(int i=1,s,t;i<=q;i++){
			read(s);read(t);ll ans=inf;
			for(auto j:p[s]) for(auto k:p[t]) _min(ans,j.se+k.se+dp[j.fi][k.fi]);
			printf("%lld\n",ans+w[s]+w[t]);
		}
	}
}

int main(){
//	int _=clock();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	read(T);
	while(T--) SHEEP::work();
//	cerr<<clock()-_<<endl;
	return 0;
} 
