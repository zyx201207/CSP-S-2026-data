#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1000005],cnt=0,s=0,d=0;
	char b[1000005],c[1000005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		cnt=cnt+a[i];
	}
	for(int i=1;i<=n;i++)
	{
			d++;
			c[d]=b[i];
	}
	for(int i=1;i<=cnt/2+1;i++)
	{
		for(int j=cnt/2+1;j>=1;j--)
		{
			if(c[i]!=c[j])
			{
				s++;
			}
		}
	}
	cout<<s;
	return 0;
}
