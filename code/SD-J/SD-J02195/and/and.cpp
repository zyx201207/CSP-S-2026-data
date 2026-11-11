#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N];
int n,m,maxx,ands,maz;
void DFS(int x,int cnt,int ans)
{
	if (cnt>m)
	{
		return ;
	}
	if (x>=n+1)
	{
		if (cnt==m)
		{
			maz=max(maz,ans);
		}
		return ;
	}
	if (ans==0)
	{
		DFS(x+1,cnt+1,a[x]);
		DFS(x+1,cnt,0);
	}
	else
	{
		DFS(x+1,cnt+1,ans&a[x]);
		DFS(x+1,cnt,ans);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxx=max(maxx,a[i]);
	}
	if (m==1)
	{
		cout<<maxx;
	}
	else if (m==n)
	{
		ands=a[1];
		for (int i=2;i<=n;i++)
		{
			ands=(ands&a[i]);
		}
		cout<<ands; return 0;
	}
	else if (m==2)
	{
		int ma=0;
		for (int i=1;i<n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma; return 0;
	}
	else
	{
		DFS(1,0,0);
		cout<<maz;
	}
	
	return 0;
} 

