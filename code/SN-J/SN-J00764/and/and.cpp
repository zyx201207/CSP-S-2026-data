#include<bits/stdc++.h>
using namespace std;
long long a[100005];
string f(long long x)
{
	string s;
	while(x)
	{
		s+=char(x%2)+'0';
		x=(x-x%2)/2;
	}
	return s;
}
long long f2(string s)
{
	long long ans=0,cnt=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		ans+=cnt*(s[i]-'0');
		cnt*=2;
	}
	return ans;
}
string f3(string s1,string s2)
{
	string s="";
	if(s1.size()<s2.size())
	{
		for(int i=0;i<=s2.size()-s1.size();i++)
		{
			s1='0'+s1;
		}
	}
	else if(s1.size()>s2.size())
	{
		for(int i=0;i<=s1.size()-s2.size();i++)
		{
			s2='0'+s2;
		}
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s2[i])
		{
			s=s+'1';
		}
		else
		{
			s=s+'0';
		}
	}
	return s;
}
int main()
{
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a,a+n+1);
		cout<<a[n]<<endl;
		return 0;
	}
	if(m==2)
	{
		long long ans2=-1e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans2=max(ans2,f2(f3(f(a[j]),f(a[i]))));
			}
		}
		cout<<ans2<<endl;
		return 0;
	}
	if(m==n)
	{
		long long ans=0;
		for(int i=1;i<n;i++)
		{
			ans=f2(f3(f(a[i]),f(a[i+1])));
		}
		cout<<ans<<endl;
		return 0;
	}
}
