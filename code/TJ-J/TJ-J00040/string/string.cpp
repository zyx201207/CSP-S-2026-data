#include<bits/stdc++.h>
using namespace std;
int num(string s)
{
	long long k=s.size();
	long long k2=k/2;
	long long ans=0;
	for(int i=0;i<k2;i++)
	{
		if(s.at(i)!=s.at(k-i-1))
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	long long n=0;
	string s="";
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		long long a=0;
		char b='0';
		cin>>a>>b;
		for(int i=0;i<a;i++)
		{
			s+=b;
		}
	}
	cout<<num(s);
	return 0;
}
