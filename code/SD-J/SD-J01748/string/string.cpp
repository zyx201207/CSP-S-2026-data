#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	s+=' ';
	for(int i=1;i<=n;i++)
	{
		int c;
		char ch;
		cin>>c;
		cin>>ch;
		for(int j=1;j<=c;j++)
		{
			s+=ch;
		}
	}
	long long ans=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]!=s[s.size()-1+1-i])
		{
			ans++;
		 } 
	}
	cout<<ans/2<<endl;
	return 0;
}
