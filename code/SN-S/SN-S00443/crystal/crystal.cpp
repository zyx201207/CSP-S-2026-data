//SN-S00443 何昊雨铮 西安铁一中国际合作学校 
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char cc;
	while(1){cc=getchar();if(cc=='-'||('0'<=cc&&cc<='9'))break;}
	int sum=0,flag=1;
	cc=='-'?flag=-1:sum=(cc^48);
	while(1){cc=getchar();if(cc<'0'||'9'<cc)break;sum=(sum<<1)+(sum<<3)+(cc^48);}
	return sum*flag;
}
inline void print(int x)
{
	if(!x)putchar('0');
	if(x<0){putchar('-');x=-x;}
	int cntt=0,numm[25];
	while(x){numm[++cntt]=x%10;x/=10;}
	for(int i=cntt;i>=1;i--)putchar('0'+numm[i]);
	putchar('\n');
	return;
}
const int N=5e5+5;
int a[N],sum[N];
int cal(int l,int r)
{
	return sum[r]-sum[l-1];
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int ret=0;
		for(int j=1<<20;j;j>>=1)
			if(i-(ret+j)>=1&&(ret+j)*a[i]-cal(i-(ret+j),i-1)<=m)
				ret+=j;
		ans=max(ans,ret+1);
	}
	print(ans);
	return 0;
}
//5 5
//1 2 4 8 9

