#include <iostream>
#include <string>
using namespace std;
int a[1000000000];
int b[1000000000];
int c[100000];
int m,n;
int main(){
	
	freopen("cards.in","r",stdin);
	freopen("cards.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		
	}
	int cnt=0;
	int k;
	for(int u=1;u<=m;u++)
	{
	
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i];
	}
	for(int i=u;i<=m;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]=i)
			{
				cnt++;
				if(cnt=1)
				{
					k=j;
				}
				else
				{
					for(int l=k+1;k+1<=j;k++)
					{
						a[l]=0;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
	}
}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
