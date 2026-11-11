#include<bits/stdc++.h>
using namespace std;
int n,a1,c1,sum,s[100000000],t[100000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a1>>c1;
		for(int j = i;j<=a1;j++)
		{
			s[j]=c1;
		}
	}
	for(int i = n;i>=1;i++)
	{
	    for(int j = 1;j <=n;j++)
	    {
	    	s[i]=t[j];
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(s[i]!=t[i])
		{
			sum++;
		}
		
	}
	cout << sum;
	return 0;
}