#include <iostream>  
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin<<a[i];
	}
	int ans=0;
	if(m==2)
	{
		int lz=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i]&a[j]>lz)
				{
					lz=i&j;
				}
			}
		}
		cout<<lz;
		return 0;
	}
	if(m==1)
	{
		int lz=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>lz)
			{
				lz=a[i];
			}
		}
		cout<<lz;
		return 0;
	}
	return 0; 
} 
