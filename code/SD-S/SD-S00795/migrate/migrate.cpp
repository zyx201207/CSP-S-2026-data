#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd()
{
	int x=0;bool f=0;char c=getchar();
	for(;!isdigit(c);f=c=='-',c=getchar());
	for(;isdigit(c);x=(x<<3)+(x<<1)+(c^48),c=getchar());
	return f?-x:x;
}
int x[2000005],f[5005][5005],y[5005][5005],l[5005],r[5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd(),t=rd();
	while(t--)
	{
		int n=rd(),d=rd();
		for(int i=1;i<=n;i++)
			x[i]=rd();
		if(c==11||c==12)
		{
			int m=d/(x[2]-x[1]);
			if(m<=1||m*2-1>n)puts("0");
			else cout<<n-(m*2-1)<<'\n';
			continue;
		}
		if(c==13||c==14)
		{
			int p=2;
			for(int i=2;i<=n;i++)
				if(x[i]-x[1]<=d)p=i;
				else break;
			if(x[n]-x[p-1]<=d)puts("0");
			else puts("2");
			continue;
		}
		int tot=0;
		for(int s=1,e=1;e<=n;e++)
			if(x[e+1]-x[e]>d||e==n)
			{
				l[++tot]=s,r[tot]=e;
				if(e-s+1<=3)tot--;
				s=e+1;
			}
		int ans=0;
		for(int k=1;k<=tot;k++)
		{
			for(int i=l[k];i<=r[k];i++)
				y[i][0]=i;
			for(int i=l[k];i<r[k];i++)
				for(int j=i+1,m=0;j<=r[k];j++)
					if(x[j]<=x[y[i][m]]+d)f[i][j]=m+1; 
						else y[i][++m]=j-1,f[i][j]=m+1;
			for(int i=l[k];i<r[k];i++)
				for(int j=y[i][1]+1;j<=r[k];j++)
				{
					int cnt=0;
					for(int p=i+1;p<j;p++)
						if(f[i][p]+f[p][j]==f[i][j])
							cnt++;
					if(cnt==2)ans++;
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
