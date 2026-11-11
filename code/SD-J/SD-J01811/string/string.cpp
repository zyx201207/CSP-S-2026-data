#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int s2=s.size();
	int z=0;
	if(s2%2==0)
	{
		s2/=2;
	}
	else
	{
		s2/=2;
		s2+=1;
	}
	for(int i=0;i<=s2;i++)
	{
		if(s[i]!=s[s2-1])
		{
			z++;
		}
	}
	cout<<z;
	return 0;
}
