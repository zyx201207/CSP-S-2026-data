#include<bits/stdc++.h>
using namespace std;
string s,s1;
long long n,a,m,l,r,t,ans,cnt;
char c;
bool flag=true;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	while(n--)
	{
		cin>>a>>c;
		long long i=0;
		ans+=a;
		while(i<=1e9&&a)
		{
			i++;
			s=s+c;
			a--;
		}
		if(n==0)
		{
			t=ans;
		}
	}
	l=0;
	r=t-1;
	while(l<r||l==r)
	{
		if(s[l]!=s[r])
		{
			flag=false;
			break;
		}
		l++;
		r--;
	}
	if(flag)
	{
		cout<<0;
		return 0;
	}
	n=m;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	l=0;
	r=t-1;
	while(l<r||l==r)
	{
		if(s[l]!=s[r])
		{
			s[r]=s[l];
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
