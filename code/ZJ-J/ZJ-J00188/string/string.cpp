#include<bits/stdc++.h>
using namespace std;
string s="",st="";
int n,a[100001];bool f;
int ans;
char c[100001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1])
		{
			f=true;
		}
	}
	if(f==0)
	{
		cout<<0;
	}
	for(int i=1;i<=n;i++)
	{
		while(a[i]!=0)
		{
			s=s+c[i];
			a[i]--;
		}
	}
	for(int i=s.size()-1;i>=0;i--)
	{
		st=st+s[i];
	}
	if(s==st)
	{
		cout<<0;
	}
	int cnt=s.size();
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[cnt-1-i])
		{
			ans++;
		}
		
	}
	cout<<ans;
}