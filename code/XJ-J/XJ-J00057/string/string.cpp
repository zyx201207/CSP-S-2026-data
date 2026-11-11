#include<bits/stdc++.h>
using namespace std;
int n;
long long x;
char c;
string s;
int ans;
bool fun(string s_)
{
	for(int i=0;i<s_.size()/2;i++) 
	{
		if(s[i]!=s[s_.size()-i-1])
		{
			return false;
		}
	} 
	return true;
} 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>c;
		for(int i=1;i<=x;i++)
		{
			s+=c;
		}
	} 
	if(fun(s))
	{
		cout<<'0';
		return 0;
	}
	int l,r;
	if(s.size()%2==1)
	{
		l=s.size()/2-1;
		r=s.size()/2+1;
	}
	else
	{
		l=s.size()/2-1;
		r=s.size()/2;
	}
	while(l>=0&&r<=s.size()-1)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l--;
		r++;
	} 
	cout<<ans;
	return 0;
} 
