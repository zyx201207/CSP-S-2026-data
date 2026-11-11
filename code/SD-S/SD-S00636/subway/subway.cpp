#include<cstdio>
#include<algorithm>
#include<iostream>
#define int long long
using namespace std;
const int M=5e6+5,N=1005;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,w[M];
long long F[N][N];
inline void rd(int &x){
	char c;x=0;
	while(c=getchar(),c<'0'||c>'9');
	do x=(x<<3)+(x<<1)+(c-48);
	while(c=getchar(),c>='0'&&c<='9');
}
int len[20][M],tim[20][M],siz[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	rd(c);rd(n);rd(m);rd(d);rd(q);
	for(int i=1;i<=m;i++)rd(w[i]);
	for(int i=1,k;i<=n;i++){
		rd(k);
		for(int j=1,u,t;j<=k;j++){
			rd(u);rd(t);
			len[++siz[u]][u]=i;
			tim[siz[u]][u]=t;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)F[i][j]=inf;
	for(int s=1;s<=m;s++){
		for(int i=1;i<=siz[s];i++)
			for(int j=1;j<=siz[s];j++){
				F[len[i][s]][len[j][s]]=min(F[len[i][s]][len[j][s]],(long long)(tim[i][s]+tim[j][s]));
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
	while(q--){
		int x,y;rd(x);rd(y);
		long long ans=inf;
		for(int i=1;i<=siz[x];i++)
			for(int j=1;j<=siz[y];j++)
				ans=min(ans,F[len[i][x]][len[j][y]]+tim[i][x]+tim[j][y]+w[x]+w[y]);
		cout<<ans<<"\n";
	}
}
