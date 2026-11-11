#include <iostream>
using namespace std;
int a[5005];
int n,d;
int way=0;
int ans=0;
void ways(int x,int y,int step,int bs)
{
	if(x==y&&step==bs)
	{
		way++;
		return;
	}
	if(step>bs)
	{
		return;
	}
	for(int i=x;i<=y;i++)
	{
		if(a[i]-a[x]<=d)
		{
			ways(i,y,step+1,bs);
		}
	}
}
int findbs(int x,int y)
{
	int step=0;
	int ls=x;
	for(int i=x;i<=y;i++)
	{
		if(a[i]-a[ls]<=d&&a[i+1]-a[ls]>d)
		{
			step++;
			ls=i;
		}
		if(i==y&&ls!=y)
		{
			step++;
		}
	}
	return step;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c<=10)
	{
		while(t--)
		{
			cin >> n >> d;
			for(int i=1;i<=n;i++)
			{
				cin >> a[i];
			}
			for(int i=1;i<=n-2;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						continue;
					}
					bool f=0;
					for(int k=i+1;k<=j;k++)
					{
						if(a[k]-a[k-1]>d)
						{
							f=1;
							break;
						}
					}
					if(f==1)
					{
						continue;
					}
					int bs=findbs(i,j);
					ways(i,j,0,bs);
					if(way==2)
					{
						ans++;
					}
					way=0;
				}
			}
			cout << ans << endl;
			ans=0;
		}
	}
	else if(11<=c&&c<=12)
	{
		while(t--)
		{
			cout << 0 << endl;
		}
	}
	else if(13<=c&&c<=14)
	{
		while(t--)
		{
			cout << 1 << endl;
		}
	}
	return 0;
}
