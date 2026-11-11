#include<bits/stdc++.h>
using namespace std;
int flag,f;
long long n,m,sum,ans,mj,p;
long long a[500010];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			f=1;
		}
		else
		{
			f=0;
			break;
		}
	}
	if(f==1)
	{
		cout<<n;
		return 0;
	}
	int cha=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		if(a[i+1]-a[i]==cha)
		{
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		for(int i=1;i<=n;i++)
		{
			p+=i*cha;
			if(m>=p)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			mj=m,sum=0;
			for(int j=i-1;j>=1;j--)
			{
				int h=a[i]-a[j];
				if(mj>=h)
				{
					sum++;
					mj-=h;
				}
				if(mj==0||mj<a[i]-a[j-1])
				{
					break;
				}
			}
			ans=max(ans,sum);
		}
	}
	cout<<ans+1;
	return 0;
}
