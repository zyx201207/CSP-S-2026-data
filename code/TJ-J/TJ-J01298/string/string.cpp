#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,L,cnt=0;
	string s,c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	L=s.length();
	for(int i=1;i<=L/2;i++)
	{
		if(s[i]!=s[L+1-i])
		{
			s[L+1-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
