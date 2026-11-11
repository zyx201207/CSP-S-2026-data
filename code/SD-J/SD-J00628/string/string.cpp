#include <bits/stdc++.h>
using namespace std;

int n,a,c,s[100000005],num,sum;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i =1;i<=n;i++)
	{
		cin>>a;
		num+=a;
		for(int j=1;j<=a;j++)
		{
			cin>>s[j];
		}
	}
	for(int i =1;i<=num;i++)
	{
		if(s[i]!=s[num-i])
		{
			s[i]=s[num-i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
