#include <bits/stdc++.h>
using namespace std;
string a,b;
char bl;
long long al,n,c1,c2,c3;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>al>>bl;
		c1+=al;
		for(long long j=1;j<=al;j++)
		{
			a+=bl;
		}
	}//np
	for(long long i=c1-1;i>=0;i--)
	{
		b+=char(a[i]);
	}//问题在这里！！！ 
	for(long long i=0;i<=c1-1;i++)
	{
		if(a[i]!=b[i])
		{
			c3++;
		}
	}
	cout<<(c3+1)/2;
	return 0;
}
