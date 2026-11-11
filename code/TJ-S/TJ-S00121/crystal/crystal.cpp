#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],maxx=0,n,m;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=m;
	int y=1,z=0;
	for(int i=1;i<=n;i++)
	{	
		y=1;
		for(int j=1;j<=n;j++)
		{
			z++;
			a[j]++;
			cnt--;
			if(a[j]==a[(n+2-1)/2] and z<=m and cnt>0)
			{
				y++;
			}
			if(cnt==0)
			{
				break;
			}
		}
		maxx=max(maxx,y+1);
	}
	cout<<maxx;
	return 0;
}
