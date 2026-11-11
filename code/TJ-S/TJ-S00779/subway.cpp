#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=5e5+5,Q=1e5+5;
#define ll unsigned long long
int c,n,m,d,q,w[M],k[N],x[Q],y[Q],dp[N][N],a[N][N],t[N][N];
int read()
{
	int x;
	char c;
	bool f=0;
	while((c=getchar())<'0')  if(c=='-') {f=1;}
	x=c^'0';
	while((c=getchar())>='0') x=x*10+(c^'0');
	return f?(~x+1):x;
}
inline void print(int n)
{
	if(n<0){
		putchar('-');
		n*=-1;
	}
	if(n>9)  print(n/10);
	putchar(n%10+'0');
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)  w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k[i]=read();
		for(int j=1;j<=k[i];j++)  a[i][j]=read(),t[i][j]=read();
	}
	for(int i=1;i<=q;i++) x[i]=read(),y[i]=read();
	if(c>=7&&c<=11)
	{
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++) dp[i][i]=0;
		
		for(int i=1;i<=n;i++)
		{
			if(k[i]==2)
			{
				dp[a[i][1]][a[i][2]]=t[i][1]+t[i][2];
			}
		}
		
		for(int k=1;k<=n;k++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int i=1;i<=n;i++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
					//cout<<dp[i][j]<<" ";
				}
			}
		}
		
		for(int i=1;i<=q;i++)
		{
			cout<<min(dp[y[i]][x[i]],dp[x[i]][y[i]])+w[x[i]]+w[y[i]]<<endl;
		}
		return 0;
	}
} 
