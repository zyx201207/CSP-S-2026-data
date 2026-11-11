#include <bits/stdc++.h>
using namespace std;
string s[10000000+10];
int main()
{ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x=0,mx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		long long a;
		cin>>a>>c;
		while(a>0)
		{
			a--;
			x++;
			s[x]=c;
		}
	}
	for(int i=1;i<=x/2;i++)
	{
		if(s[i]!=s[x+1-i])
		{
			mx++;
		}
	}
	cout<<mx;
	return 0;
}
