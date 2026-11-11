#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	int i,n,t=0,j,s,x,r;
	cin>>n>>s;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=1;j<=i;j++)
		{
			if(a[j]==a[i])
			{
				for(t=j;t<=i;t++)
				{
					a[s]=0;
				}
			}
		}
	}
	cout<<a[s];
	return 0;
}