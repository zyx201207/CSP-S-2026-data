#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l[n];
	long long r[n];
	char ax[n];
	long long lx=0;
	for(int i=0,x;i<n;i++)
	{
		cin>>x>>ax[i];
		if(i>0&&ax[i]==ax[i-1])
		{
			r[i-1]+=x;
			lx+=x;
			i--;
			n--;
			continue;
		}
		else
		{
			l[i]=lx;
			lx+=x;
			r[i]=lx-1;
		}
	}
	long long ans=0;
	long long mid=lx/2.0;
	int jx;
	int ly=0;
	int ab=0,cd=n;
	while(ab<cd)
	{
		int i=ab+(cd-ab*1.0)/2;
		if(r[i]>=mid&&l[i]<=mid)
		{
			jx=i;
			//if(((r[i]-l[i])%2==0&&lx%2==1)||((r[i]-l[i])%2==1&&lx%2==0))
			//{
				if(mid-l[i]!=r[i]-mid&&lx%2==0)
				{
					ans+=abs(mid-l[i]-r[i]+mid)+1;
					if(mid-l[i]<r[i]-mid)
					{
						l[i]=mid-r[i]+mid-1;
						r[i-1]=l[i]-1;
						if(r[i-1]-l[i-1]<0)
						{
							ly++;
						}
					}
					else
					{
						r[i]+=abs(mid-l[i]-r[i]+mid)-1;
						l[i+1]=r[i]+1;
						if(r[i+1]-l[i+1]<=0)
						{
							n--;
						}
					}
				}
				if(mid-l[i]-1!=r[i]-mid&&lx%2==1)
				{
					ans+=abs(mid-l[i]-r[i]+mid);
					if(mid-l[i]<r[i]-mid)
					{
						l[i]=mid-r[i]+mid;
						r[i-1]=l[i]-1;
						if(r[i-1]-l[i-1]<0)
						{
							ly++;
						}
					}
					else
					{
						r[i]+=abs(mid-l[i]-r[i]+mid);
						l[i+1]=r[i]+1;
						if(r[i+1]-l[i+1]<=0)
						{
							n--;
						}
					}
				}
			//}
			break;
		}
		else
		{
			if(l[i]>=mid)
			{
				cd=i;
			}
			else
			{
				ab=i;
			}
		}
	}
	for(int i=ly;i<jx;i++)
	{
		if(ax[i]!=ax[n-i-1])
		{
			ans+=r[i]-l[i]+1;
			ax[i]=ax[n-i-1];
		}
		if(r[i]-l[i]!=r[n-i-1]-l[n-i-1]&&ax[i]==ax[n-i-1])
		{
			ans+=max(r[i]-l[i],r[n-i-1]-l[n-i-1]);
			if(i==jx-1&&l[jx]-r[i]!=1)
			{
				ans-=l[jx]-r[i];
			}
			if(r[i]-l[i]<r[n-i-1]-l[n-i-1])
			{
				l[n-i-1]=r[n-i-1]-r[i]+l[i];
				r[n-i-2]=l[n-i-1]-1;
			}
			else
			{
				r[i]=l[i]+r[n-i-1]-l[n-i-1];
				l[i+1]=r[i]+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
