#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	long long a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			if(a[j-1]>a[j])
			{
				int t=a[j-1];
				a[j-1]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << a[i];
	}
	return 0;
}
