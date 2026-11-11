#include<bits/stdc++.h>
using namespace std;
const int N=500005,C=300005;
int a[N],n,hsh[C],m,b[N];
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int t=n;t;t--)
	{
		int cnt=0;
		for(int i=t;i<=n;i++)
		{
			int pos=cnt+1;
			for(int j=1;j<=cnt;j++)if(b[j]==a[i]){pos=j;break;}
			cnt=pos,b[pos]=a[i];
		}
		for(int i=1;i<=cnt;i++)hsh[b[i]]++;
	}
	for(int i=1;i<=m;i++)printf("%d%c",hsh[i],i==m?'\n':' ');
	return 0;
}