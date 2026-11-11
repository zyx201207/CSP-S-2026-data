#include <bits/stdc++.h>
using namespace std;
string s,s_lin,s_first,s_last;
long long n,a,m,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s_lin;
		for(int i=1;i<=a;i++)
		{
			s+=s_lin;
		}
	}
	for(int i=0;i<=s.length()/2-1;i++)
	{
		s_first+=s[i];
	}
	if(s.length()%2==1)
	{
		m=s.length()/2+1;
	}
	else
	{
		m=s.length()/2;
	}
	for(int i=s.length()-1;i>=m;i--)
	{
		s_last+=s[i];
	}
	for(int i=0;i<=s.length()/2-1;i++)
	{
		if(s_first[i]!=s_last[i]) ans++;
	}
	cout<<ans;
	return 0;
}
