#include<iostream>
using namespace std;
int a[1005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	int x;
	int maxn=0;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	
	}
	while(x--)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]&a[i-1]>=maxn)
			{
				maxn=a[i]&a[i-1];
			}
		}
	}
	cout<<maxn;
	
	
	
	
	
	
	
	
	
	return 0;
}
