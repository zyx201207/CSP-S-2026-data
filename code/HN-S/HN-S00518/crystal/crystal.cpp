#include <iostream>
#include <cstdio>
using namespace std;
int a[5005],ans,b,c,n,m,p,q;
bool x,y;
void d(int i)
{
	if(a[i]<a[i-1])
	{
		a[i-1]+=a[i];
		a[i]=a[i-1]-a[i];
		a[i-1]-=a[i];
		d(i-1);
	}
	if(i<n) d(i+1);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	d(1);
	for(int i=0;i<n-1;i++)
	{
		c=m;
		b=0;
		p=1,q=1;
		while(1)
		{
			x=(i-q>=0);
			y=(i+p<=n);
			if(x&&y)
			{
				if(a[i+p]-a[i]>a[i]-a[i-q])
				{
					c=c-a[i]+a[i-q];
					q++;
					if(c>=0)
					{
						b++;
					}
				}
				else
				{
					c=c-a[i+p]+a[i];
					p++;
					if(c>=0)
					{
						b++;
					}
				}
			}
			else if(x)
			{
				c=c-a[i]+a[i-q];
				q++;
				if(c>=0)
				{
					b++;
				}
			}
			else if(y)
			{
				c=c-a[i+p]+a[i];
				p++;
				if(c>=0)
				{
					b++;
				}
			}
			else break;
			if(c<=0) break;
		}
		if(b>ans)
		{
			ans=b;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
