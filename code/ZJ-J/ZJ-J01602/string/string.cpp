#include<bits/stdc++.h>
using namespace std;
char s[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,len=1,sum=0,flag=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=a;j>=1;j--)
		{
			s[len]=c;
			len++;
		}
	}
	len--;
	
	  
	long long i=1,j=len;
	while(i<j)
	{
		if(s[i]!=s[j])
		{
			sum++;
		}
		i++;
		j--;
	}
	cout<<sum;
	return 0;
}
