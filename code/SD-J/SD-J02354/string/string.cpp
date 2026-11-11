#include<bits/stdc++.h>
using namespace std;
char s[10000005];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	long long m=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		char c;
		cin>>k>>c;
		for(int j=1;j<=k;j++)
		{
			m++;
			s[m]=c;
		}
	}
	int sum=0;
	for(int i=1;i<=m/2;i++)
	{
		if(s[i]!=s[m-i+1])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
