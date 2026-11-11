#include <bits/stdc++.h>
using namespace std;
int x,n,m,er[33],maxx,ans;
bool a[200005][33],p[200005];
void zhuan(int o,int id)
{
	for (int i=30;i>=0;i--)
	{
		if (o>=er[i])
		{
			o-=er[i];
			a[id][i]=true;
			maxx=max(maxx,i);
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	er[0]=1;
	for (int i=1;i<=30;i++)
	{
		er[i]=er[i-1]*2;
	}
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		zhuan(x,i);
	}
	for (int i=maxx;i>=0;i--)
	{
		int cnt=0;
		for (int j=1;j<=n;j++)
		{
			if (!p[j] && a[j][i])
			{
				cnt++;
			}
		}
		if (cnt>=m)
		{
			ans+=er[i];
			for (int j=1;j<=n;j++)
			{
				if (!a[j][i])
				{
					p[j]=true;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
