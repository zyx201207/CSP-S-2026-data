#include<bits/stdc++.h>
using namespace std;
char s[10000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char b;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=a;j++)
		{
			sum++;
			s[sum] = b;
		}
	}
	int cnt=0; 
	for(int i=1;i<=sum/2;i++)
	{
		if(s[i]!=s[sum+1-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
