#include<iostream>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m,maxa=-1,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	if(m==1)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]>maxa)
			{
				maxa=a[i];
			}
		}
		cout<<maxa;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[j]<a[j+1])
				{
					swap(a[j],a[j+1]);
				}
			}
		}
		cout<<a[m];
	}
	return 0;
 } 
