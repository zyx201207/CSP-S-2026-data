#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","W",stdout);
	long long n,m;
	long long sum=0,len=0;
	char s;
	string str;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> m>>s;
		len+=m;
		for(int k=1;k<=m;k++)
		{
			str+=s;
		}
	} 
	cout << len <<endl;
	for(long long i=len/2;i>=1;i--)
	{
		if(str[i-1]!=str[len-i])
		{
			sum+=1;
		}
	}	
	cout << sum;
	return 0;
} 






