#include <bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if(x>9)
	{
		write(x/10);
	}
	putchar(x%10+48);
	return;
}
long long n,m,a[500005],b[500005];
int t,c[500005],ans=0;
int main()
{
	// freopen("1.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i = 1;i <= n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	t=1;c[1]=1;b[1]=a[1];
	for(int i = 2;i <= n;i++)
	{
		if(a[i]==a[i-1])
		{
			c[t]++;
		}
		else
		{
			b[++t]=a[i];
			c[t]=1;
		}
	}
	// for(int i = 1;i <= t;i++)
	// {
	// 	cout<<b[i]<<' '<<c[i]<<endl;
	// }
	long long sum=0;
	int cnt=0,d=1,e=c[d];
	for(int i = 1;i <= t;i++)
	{
		sum+=(b[i]-b[i-1])*cnt;
		cnt+=c[i];
		// cout<<i<<' '<<sum<<' '<<cnt<<endl;
		while(sum>m)
		{
			long long s=(b[i]-b[d])*e;
			if(sum-s>=m)
			{
				sum-=s;
				cnt-=e;
				d++;
				e=c[d];
			}
			else
			{
				int l=1,r=e,mid;
				while(l<=r)
				{
					mid=((l+r)>>1);
					s=(b[i]-b[d])*mid;
					if(sum-s>m)
					{
						l=mid+1;
					}
					else
					{
						r=mid-1;
					}
				}
				sum-=s;
				cnt-=mid;
				e-=mid;
				if(e==0)
				{
					d++;
					e=c[d];
				}
				// cout<<"+++"<<i<<' '<<sum<<' '<<cnt<<' '<<d<<' '<<e<<' '<<r<<' '<<endl;
			}
		}
		// cout<<i<<' '<<sum<<' '<<cnt<<endl;
		ans=max(ans,cnt);
	}
	write(ans);
	return 0;
}