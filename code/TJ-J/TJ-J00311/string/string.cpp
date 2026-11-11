#include<bits/stdc++.h>

using namespace std;
int n;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long ans=s.size(),cnt=0;
	for(int i=0;i<ans/2;i++)
	{
		if(s[i]!=s[ans-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}


