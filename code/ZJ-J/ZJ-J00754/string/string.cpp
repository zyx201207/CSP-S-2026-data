#include<bits/stdc++.h>
using namespace std;
string s="";
int n,a;
char c;
int f(string s)
{
	int ans=0;
	for(int i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			ans++;
		}
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	cout<<f(s);
	
	return 0;
}
