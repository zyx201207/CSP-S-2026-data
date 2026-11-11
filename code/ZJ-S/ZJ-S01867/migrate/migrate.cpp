#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
const long long inf=4e18;
int Type,n,T,R;
long long a[N],D,ans,c[N];
struct pig
{
	long long v;
	int cnt;
}tr[N<<2],f[N];
long long in()
{
	long long w=1,num=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		  w=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	  num=num*10+ch-48,ch=getchar();
	return w*num;
}
void FR()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
int main()
{
	FR();
	Type=in(),T=in();
	while(T--)
	{
		n=in(),D=in();
		for(int i=1;i<=n;++i)
		  a[i]=in();
		ans=0;
		if(Type<=10)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				  f[j]={inf,0},c[j]=0;
				f[i]={0,1};
				c[0]=1;
				R=i;
				for(int j=i-1;j>=1;--j)
				{
					if(a[j+1]-a[j]>D)
					  break;
					while(a[R]>a[j]+D)
					  c[f[R].v]-=f[R].cnt,--R;
					f[j]={f[R].v+1,c[f[R].v]};
					c[f[j].v]+=f[j].cnt;
				}
				for(int j=i;j>=1;--j)
				  if(f[j].v!=inf&&f[j].cnt==2)
				    ++ans;
			}
		}
		if(Type==11||Type==12)
		{
			if(D>=(a[2]-a[1])*2)
			  ans=max(0ll,n-D/(a[2]-a[1])*2+1);else
			  ans=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//48 latest
