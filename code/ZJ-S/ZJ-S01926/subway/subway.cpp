#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int maxn=500+5;
const int maxm=5e5+5;
const int maxd=20+5;
int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int Typ,n,m,d,q;
int w[maxm];
int len[maxm],id[maxm][maxd],val[maxm][maxd];
ll dis[maxn][maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	Typ=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			id[a][++len[a]]=i;
			val[a][len[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++){
			int x=id[i][j];
			for(int k=1;k<j;k++){
				int y=id[i][k];
				dis[x][y]=min(dis[x][y],1ll*val[i][j]+val[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||j==k) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x=read(),y=read();
		ll ans=inf;
		for(int i=1;i<=len[x];i++){
			for(int j=1;j<=len[y];j++){
				ans=min(ans,dis[id[x][i]][id[y][j]]+val[x][i]+val[y][j]+w[x]+w[y]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}