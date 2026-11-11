#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int res[N],ans=0,sum[N];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	int l=1,r=n;
	for(int i=1;i<=n;++i)
	{
		int mid=l+r>>1;
		res[i]=a[mid]-a[i];
	}
	for(int i=1;i<=n;++i)
	{
		if(res[i]==0)
		{
			ans++;
		}
		sum[i]=res[i-1]+res[i];
		if(sum[i]>=m)
		{
			ans+=2;
		}
	}
	printf("%d",ans);
	return 0;
}