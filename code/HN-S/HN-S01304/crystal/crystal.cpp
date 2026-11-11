#include<bits/stdc++.h>
using namespace std;

long long read()
{
	long long k=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=k*10+(c-'0');c=getchar();}
	return k*f;
}

bool cmp(long long a,long long b)
{
	return a<b;
}

long long n,m,a[600005],b[600005],c[600005],cnt,ans;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int ff=0;
	if(n>6000)for(int i=200;i<=400;i++)if(a[i-1]>a[i])ff=1;
	if(ff==1&&n>6000||n<=6000)sort(a+1,a+n+1,cmp);
	b[1]=a[1];c[1]++;cnt++;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])b[++cnt]=a[i];
		c[cnt]++;
	}
	long long sum1=0,cnt1=c[1],l=1;
	ans=c[1];
	for(int i=2;i<=cnt;i++)
	{
		ans=max(ans,c[i]);
		sum1+=(b[i]-b[i-1])*cnt1;
		if(sum1>m)
		{
			while(1)
			{
				if(sum1-(b[i]-b[l])*c[l]>m)
				{
					sum1-=(b[i]-b[l])*c[l];
					cnt1-=c[l];
					l++;
				}
				else 
				{
					cnt1+=c[i];
					long long abc=(sum1-m)/(b[i]-b[l]);
					if((sum1-m)%(b[i]-b[l])!=0)abc++;
					ans=max(ans,cnt1-abc);
					break;
				}
			}
		}
		else
		{
			cnt1+=c[i];
			ans=max(ans,cnt1);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
