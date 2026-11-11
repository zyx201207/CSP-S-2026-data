#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[300000];
	char b[300000];
	string s;
	int len=0;
	int cnt=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			s+=b[i];
		}
		len+=a[i];
	}
	
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(b[0]==b[1]) cout<<0;
		else cout<<min(a[0],a[1]);
		return 0;
	}
	
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			s[len-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt-1;
	return 0;
}
