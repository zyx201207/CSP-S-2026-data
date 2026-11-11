#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
string s,ip;
int n,rd,cnt=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>rd>>ip;
		for(int i=1;i<=rd;i++)
			s+=ip;
	}
	if(s.size()%2==1)
	{
		for(int i=s.size()/2;i>=0;i--)
		{
			if(s[i]!=s[s.size()-i-1])
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
