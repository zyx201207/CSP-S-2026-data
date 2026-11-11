#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n<=20)
		{
			m=max(a[i],a[i-1]);
		}
	}
	
	return 0;
}
