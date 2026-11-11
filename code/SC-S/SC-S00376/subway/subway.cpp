#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define il inline
#define re register
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=506;
const int M=5e5+6;
int n,m,d,q,f[N][N],b[M];
vector<pii> a[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	read(),n=read(),m=read(),d=read(),q=read();
	memset(f,0x3f,sizeof(f));
	for(re int i=1;i<=m;i++)
		b[i]=read();
	for(re int i=1;i<=n;i++){
		re int k=read();
		for(re int j=1;j<=k;j++){
			re int x=read(),y=read();
			a[x].pb({i,y});
		}f[i][i]=0;
	}
	for(re int i=1;i<=m;i++){
		for(re int j=0;j<a[i].size();j++)
			for(re int k=j+1;k<a[i].size();k++){
				re int w=a[i][j].sc+a[i][k].sc;
				re int u=a[i][j].fs,v=a[i][k].fs;
				if(w<f[u][v])
					f[u][v]=f[v][u]=w;
			}
	}
	for(re int k=1;k<=n;k++)
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		re int s=read(),t=read(),awa=1e18;
		for(auto x:a[s])
			for(auto y:a[t])
				awa=min(awa,x.sc+y.sc+f[x.fs][y.fs]);
		printf("%lld\n",awa+b[s]+b[t]);
	}
	return 0;
}
