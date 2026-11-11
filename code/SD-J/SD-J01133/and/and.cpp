#include <bits/stdc++.h>
using namespace std;
long long a[2*10000+10],a1[2*10000+10],mx1;
bool xxx(long long a,long long b)
{
	return a>b;
}
int main()
{ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m1,m2;
	int i=1,j,k,l,m,x,z;
	cin>>n>>m1;
	m2=m1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		a1[i]=a[i];
	} 
	sort(a1+1,a1+1+n,xxx);
	while(m2>0&&i<=n)
	{

		if(a[i]%2==1)
		{
			m2--;
			if(m2=m1)
			{
				mx1=a[i];
			}
			else
			{
				mx1=mx1&a[i];
			}
		}
		i++;
	}
	if(m1==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	else if(m1==2)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>mx)
				{
					mx=(a[i]&a[j]);
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	else if(m1==3)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					if((a[i]&a[j]&a[k])>mx)
					{
						mx=(a[i]&a[j]&a[k]);
					}
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	else if(m1==4)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					for(l=k+1;l<=n;l++)
					{
						if((a[i]&a[j]&a[k]&a[l])>mx)
						{
							mx=(a[i]&a[j]&a[k]&a[l]);
						}
					}
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	else if(m1==5)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					for(l=k+1;l<=n;l++)
					{
						for(m=l+1;m<=n;m++)
						{
							if((a[i]&a[j]&a[k]&a[l]&a[m])>mx)
							{
								mx=(a[i]&a[j]&a[k]&a[l]&a[m]);
							}
						}
					}
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	else if(m1==6)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					for(l=k+1;l<=n;l++)
					{
						for(m=l+1;m<=n;m++)
						{
							for(x=m+1;x<=n;x++)
							{
								if((a[i]&a[j]&a[k]&a[l]&a[m]&a[x])>mx)
								{
									mx=(a[i]&a[j]&a[k]&a[l]&a[m]&a[x]);
								}
							}
						}
					}
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	else if(m1==7)
	{
		long long mx=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					for(l=k+1;l<=n;l++)
					{
						for(m=l+1;m<=n;m++)
						{
							for(x=m+1;x<=n;x++)
							{
								for(z=x+1;z<=n;z++)
								{
									if((a[i]&a[j]&a[k]&a[l]&a[m]&a[x]&a[z])>mx)
									{
										mx=(a[i]&a[j]&a[k]&a[l]&a[m]&a[x]&a[z]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<max(mx,mx1);
		return 0;
	}
	return 0;
}
