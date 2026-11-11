#include <bits/stdc++.h>
using namespace std;
long long a[500005];
bool flag=false;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,z=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{	
		if(m>0&&flag==false)
		{
			for(int j=1;j<=n;j++)
			{
				if((a[i+j]-a[i])*j<=m)
				{
					m-=j*(a[i+j]-a[i]);
					for(int k=0;k<j;k++)
					{
						a[i+k]=a[i+j];
					}
					if(m<=0)
					{
						flag=true;
						break;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			z+=1;
		}
	}
	cout<<z<<endl;
	return 0;
}
