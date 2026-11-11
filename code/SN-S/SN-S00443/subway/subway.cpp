//SN-S00443 何昊雨铮 西安铁一中国际合作学校
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char cc;
	while(1){cc=getchar();if(cc=='-'||('0'<=cc&&cc<='9'))break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(cc<'0'||'9'<cc)break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
inline void print(long long x)
{
	if(!x)putchar('0');
	if(x<0){putchar('-');x=-x;}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
	return;
}
const int N=505,M=5e5+5;
int w[M],cnt[M],fi[M][20],se[M][20];
long long f[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	double st=clock();
	int c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		while(k--)
		{
			int a=read(),t=read();
			fi[a][cnt[a]]=i,se[a][cnt[a]]=t;
			cnt[a]++;
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int x=1;x<=m;x++)
		for(int i=0;i<cnt[x];i++)
			for(int j=0;j<cnt[x];j++)
				if(i!=j&&se[x][i]+se[x][j]<f[fi[x][i]][fi[x][j]])
					f[fi[x][i]][fi[x][j]]=se[x][i]+se[x][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--)
	{
		int x=read(),y=read();
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<cnt[x];i++)
			for(int j=0;j<cnt[y];j++)
				ans=min(ans,f[fi[x][i]][fi[y][j]]+se[x][i]+se[y][j]);
		print(ans+w[x]+w[y]);
	}
//	double ed=clock();
//	cout<<ed-st;
	return 0;
}


