#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long c=1,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			c=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';ch=getchar();
	}
	return c*f;
}
inline void write(long long x){
	if(x<0){
		putchar('-');write(-1*x);return;
	}
	if(x>=10){
		write(x/10);
	}
	putchar('0'+x%10);
	return;
}
const long long N=605;
const long long M=500105;
const long long D=25;
const long long inf=1e18;
long long c,n,m,d,q,w[M],dis[N][N],f[M][D],e[M][D],deg[M],ans;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		long long k=read();
		for(int j=1;j<=k;j++){
			long long a=read(),t=read();deg[a]++;e[a][deg[a]]=i;f[a][deg[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dis[i][j]=dis[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<deg[i];j++){
			for(int l=j+1;l<=deg[i];l++){
				dis[e[i][j]][e[i][l]]=dis[e[i][l]][e[i][j]]=min(dis[e[i][j]][e[i][l]],f[i][j]+f[i][l]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x=read(),y=read();ans=inf;
		for(int j=1;j<=deg[x];j++){
			for(int k=1;k<=deg[y];k++){
				ans=min(ans,dis[e[x][j]][e[y][k]]+f[x][j]+f[y][k]);
			}
		}
		ans=ans+w[x]+w[y];write(ans);putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
