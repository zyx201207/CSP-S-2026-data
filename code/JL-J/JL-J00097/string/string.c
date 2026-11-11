#include<bits/stdc++.h>
using namespace std;
int main()
{
	string n,a,c,s=' ',s1=' ';
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		s=s+a*c;
	}
	for(int i=s.size();i>=0;i--)
	{
		s1=s1+s[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			sum+=1;
		}
		
	}
	cout<<sum;
	return 0;
}	
