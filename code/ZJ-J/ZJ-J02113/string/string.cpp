#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,b;
int n,x,cnt;
char c;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s="";
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		while(x--)
		{
			s+=c;
		}
	}
	b="";
	for(int i=0;i<s.size();i++)
	{
		b+=s[s.size()-i-1];
	}
	if(b==s)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
}
