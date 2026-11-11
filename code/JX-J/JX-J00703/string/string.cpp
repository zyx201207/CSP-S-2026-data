#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	long long sum=0;
	char c;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s=s+c;
		}
	}
	for(int i=0;i<s.size()-1-i;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
