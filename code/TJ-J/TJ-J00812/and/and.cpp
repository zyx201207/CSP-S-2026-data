#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2000005],ma=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if (m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;i<=n;i++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
	}
	cout<<ma;
}
