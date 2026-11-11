#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005],cnt,l;
char c1[1000005],c2[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i]>>c1[i];
		l += a[i];
	}
	b[1] = a[1];
	for(int i = 2;i <= n;i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= a[i];j++)
		{
			c2[b[i - 1] + j] = c1[i];
		}
	}
	for(int i = 1,j = l;i <= j;i++,j--)
	{
		if(c2[i] != c2[j])
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
