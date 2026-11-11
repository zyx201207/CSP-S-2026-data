#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		long long x;
		string w;
		cin>>x>>w;
		for(long long i=1;i<=x;i++)
		{
			s+=w;
		}
	}
	long long num=0;
	for(long long i=0;i<(s.size()/2);i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			num++;			
		}	
	}
	cout<<num;
	return 0;
}
