#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define eb emplace_back
#define X first
#define Y second
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
long long f[N][N];
vector<pii >E[M];
long long read(){
	long long ans=0;char c=getchar();
	while(!(c>='0'&&c<='9'))c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
void write(long long x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=1,a,t;j<=k;j++){
			a=read();t=read();
			E[a].eb(mp(t,i));
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)f[i][j]=1e18;
	for(int i=1;i<=m;i++)for(pii x:E[i])for(pii y:E[i])if(x!=y)
		f[x.Y][y.Y]=f[y.Y][x.Y]=min(f[x.Y][y.Y],(long long)(x.X+y.X));
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)if(i!=k)for(int j=1;j<=n;j++)if(j!=i&&j!=k)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(int i=1,u,v;i<=q;i++){
		u=read(),v=read();
		long long minn=1e18;
		for(pii x:E[u])for(pii y:E[v])minn=min(minn,x.X+y.X+f[x.Y][y.Y]);
		write(minn+w[u]+w[v]);
		putchar('\n');
	}
	return 0;
}

