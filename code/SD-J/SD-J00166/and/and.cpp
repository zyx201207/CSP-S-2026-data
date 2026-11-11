#include <bits/stdc++.h>
using namespace std;
long long a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<=2)
	{
		long long maxn=0,sum=a[1];
		int xb=1;
		for(int i=1;i<=n;i++)
		{
		if(i!=xb)
		{
			if((a[xb]&a[i])>maxn)
			{
				maxn=(a[xb]&a[i]);
				xb++;
			}
		}
		continue;
		}
		cout<<maxn;
	}
	else
		cout<<0;
	return 0;
}
