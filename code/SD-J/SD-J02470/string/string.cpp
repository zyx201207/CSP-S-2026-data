#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	char c;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for(int i=0;i<a;i++)
		{
			s+=c;
		}
	}
	int sum=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i])
		{
			sum++;		
		}
	}
	cout<<sum;
	return 0;
}
