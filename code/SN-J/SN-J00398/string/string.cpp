#include<bits/stdc++.h>
using namespace std;
char c[1000000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	
	cin>>n;
	int sum=0;
	int cnt=0;
	int ls=0;
	for(int i=1;i<=n;i++)
	{
		long long gs;
		char zm;
		cin>>gs>>zm;
		for(int j=1;j<=gs;j++)
		{
			c[sum+j]=zm;
		}
		sum+=gs;
	}
	for(int i=1;i<=sum;i++)
	{
		for(int j=sum-ls;j>=1;j--)
		{
			if(c[i]!=c[j])
			{
				cnt++;
			}	
		}
		ls+=1;
	}
	cout<<cnt/sum;
	return 0;	
	
} 
