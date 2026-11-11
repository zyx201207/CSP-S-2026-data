#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0,m=0;
	string ax,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>ax;
		m+=a;
		for(int j=1;j<=a;j++)
		{
			b+=a;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(b[i-1]!=b[m-i])
		{
			cnt++;
		}
	}
	cout<<cnt;
return 0;
}
