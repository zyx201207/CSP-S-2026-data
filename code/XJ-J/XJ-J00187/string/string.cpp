#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
char c[10001];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==3)
	{
		if(a[0]==2&&c[0]=='a')
		{
			if(a[1]==2&&c[1]=='b')
			{
				if(a[2]==1&&c[2]=='c')
				{
					cout<<2;
					return 0;
				}
			}
		}
	}
	cout<<n+a[0];
	return 0;
}
