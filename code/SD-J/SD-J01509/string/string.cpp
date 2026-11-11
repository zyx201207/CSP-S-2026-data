#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
bool check(string s)
{
	int l=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[l-i-1]) return false;
	}
	return true;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	long long cnt=0;
	if(check(s)) 
	{
		cout<<0;
		return 0;
	}
	else
	{
		int l=s.size();
		for(int i=0;i<l;i++)
		{
			if(s[i]!=s[l-i-1]) cnt++;
		}
	}
	cout<<cnt/2;
	return 0;
}

