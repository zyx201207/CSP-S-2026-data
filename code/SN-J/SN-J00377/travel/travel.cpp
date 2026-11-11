#include<bits/stdc++.h>
using namespace std;
int n,a[10005],cnt=1;
char b[10005],c[10000000000];
int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=cnt;j<=cnt+a[i]-1;j++)
		{
			c[cnt]=b[i];
			cnt++;
		}
	}
	int he=cnt/2,son=0;
	for(int i=1;i<=cnt;i++)
	{
		if(c[i]!=c[cnt-i+1])
		{
			son++;
		}
	}
	cout<<son;
	return 0;
}
