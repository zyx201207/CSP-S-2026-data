#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int num=0;
	for (int i=1;i<=n;i++)
	{
	    	
		cin>>a[i];
		for (int j=1;j<=i;j++)
		{
			num++;
		}
	}
	cout<<num/2-1;
}
