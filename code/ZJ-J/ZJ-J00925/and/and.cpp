#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int F[10005][10005],n,m,a[N];
int read()
{
	int ret=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c))ret=(ret<<3)+(ret<<1)+(c&15),c=getchar();
	return ret*f;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<=10000&&m<=10000)
	{
		for(int i=1;i<=n;i++)F[i][1]=a[i];
		for(int i=2;i<=n;i++)
		for(int j=2;j<=min(i,m);j++)F[i][j]=max(F[i-1][j],F[i-1][j-1]&a[i]);
		printf("%d\n",F[n][m]);return 0;
	}
	bool flg=1;
	for(int i=1;i<=n;i++)if(!a[i]||(1<<log2(a[i])+1)==i)flg=1;else{flg=0;break;}
	if(flg)
	{
		sort(a+1,a+1+n);printf("%d\n",a[m]);return 0;
	}
	int x=0;
	for(int i=1;i<=n;i++)x=max(x,a[i]);
	if(x<=4)
	{
		int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
		for(int i=1;i<=n;i++)cnt1+=a[i]==1,cnt2+=a[i]==2,cnt3+=a[i]==3,cnt4+=a[i]==4;
		if(cnt4>=m)puts("4");
		else if(cnt3>=m)puts("3");
		else if(cnt3+cnt2>=m)puts("2");
		else if(cnt3+cnt1>=m)puts("1");
		else puts("0");
		return 0;
	}
	return 0;
}