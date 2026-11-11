闫桐煊 西安交通大学附属中学 SN-J00700
#include <iostream>
using namespace std;
int main()
{
	int n,m,a[500001];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int s=1;s<=n;s++)
	{
		for(int i=s;i<=n;i++)
		{
			if(j=1;j<=n;j++)
			{
				if(a[j]==a[i])
				{
					int t=a[j];
					a[j]=a[i];
					a[i]=t;
				}
			}
		}
	}
	return 0;	
} 
