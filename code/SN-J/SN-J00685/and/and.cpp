//xinzizhang SH-J00685
//xi'anJTUfushuchuzhong
#include <bits/stdc++.h>
using namespace std;
int n,m,maxx,a[2000006];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			maxx=max(a[i]&a[j],maxx);
		}
	}
	cout<<maxx;
	return 0;
}
