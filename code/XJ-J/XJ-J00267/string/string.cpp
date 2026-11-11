#include<bits/stdc++.h>
using namespace std;

long long n,ans;

struct awa
{
	long long a;
	char c;
}b[200000];

string er(string s)
{
	string s1;
	s1="";
	long long o;
	o=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		s1+=s[i];
		o++;
	}
	return s1;
} 

string s,s1,s2,s3;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s="";
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		s+=b[i].c;
	}
	s1=er(s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			ans+=min(b[i+1].a,b[n-i].a);
		}
	}
	cout<<ans;
	
	return 0;
}
