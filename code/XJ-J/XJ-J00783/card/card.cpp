#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=1;
	while(t<=m)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==t)
			{
				ans=i;
				if(a[i-1]==a[i+1])
				{
					ans--;
				}
			}
		}
		cout<<ans<<" ";
		t++;
	}
	return 0;
}