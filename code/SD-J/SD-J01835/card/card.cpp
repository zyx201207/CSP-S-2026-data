#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005],n,m,b[300005];
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			b[a[j]]++;
			if(b[a[j]]>1)
		}
	}
	return 0;
}
