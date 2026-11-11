#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long num=0,xw=0;	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		long long a;
		string b;
		cin>>a>>b;
		for(long long i=0;i<a;i++)
		{
			s+=b;
			xw++;
		}
	}
	long long wzq=0,xxr=xw-1;
	//cout<<s<<endl<<xxr;
	if(xw%2==0)
	{
		for(long long i=0;i<xw/2;i++)
		{
			if(s[wzq]!=s[xxr])
			{
				num++;
				wzq++;
				xxr--;
			}
		}
	}
	else
	{
		for(long long i=0;i<(xw-1)/2;i++)
		{
			if(s[wzq]!=s[xxr])
			{
				num++;
				wzq++;
				xxr--;
			}
		}
	}
	cout<<num;
	return 0;
}
