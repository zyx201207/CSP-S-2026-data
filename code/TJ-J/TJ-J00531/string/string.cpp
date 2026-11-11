#include <bits/stdc++.h>
using namespace std;
long long a[10007];
char b[10007];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	int cnt=0;
	int sum=0;
	for(long long i=1;i<=10000;i++)
	{
		if(s[i]<='a'&&s[i]>='z') sum++;
	}
	cout << sum;
	if(sum%2==0)
	{
		for(int i=0;i<sum/2;i++)
		{
			if(sum%2==1) 
			{	
				if(i!=sum/2+1) 
				{
					if(s[i]!=sum-s[i]+1) cnt++;
				}
			}
			else 
			{
				if(s[i]!=sum-s[i]+1) cnt++;
			}
		}
	}
	else
	{
		for(int i=0;i<s.size()/2;i++)
		{
			if(s.size()%2==1) 
			{
				if(i!=s.size()/2+1) 
				{
					if(s[i]!=s.size()-s[i]+1) cnt++;
				}
			}
			else 
			{
				if(s[i]!=s.size()-s[i]+1) cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
