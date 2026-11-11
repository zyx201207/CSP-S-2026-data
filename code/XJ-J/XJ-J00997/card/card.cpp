#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
    int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int r=(n+1)/2,l=(n+1)/2;r>=1 && l<=n;r--,l++)
		{
			if(a[r]=a[l])
			{
				;
			}
		}
	}
	
	return 0;
}