#include<iostream>
using namespace std;
const int N=1e5+5;
int a[N],jia,dd;
int dfs(int now,int r,int bushu)
{
	if (r==now && bushu==jia) return 1;
	int ans=0;
	for (int i=now+1;i<=r;i++)
	{
		if (a[i]-a[now]<=dd) ans+=dfs(i,r,bushu+1);
		else break;
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while (t--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		dd=d;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int anss=0;
		for (int l=1;l<n;l++)
		{
			for (int r=l+1;r<=n;r++)
			{
				int minn=0;
				for (int p=l;p<=r;p++)
				{
					int len=1;
					for (;len<=r-p;len++)
					{
						if (d<a[p+len]-a[p]) 
						{
							len--;
							break;
						}
					}
					p=p+len;
					minn++;
				}
				jia=minn;
				if (dfs(l,r,0)==2) anss++;
			}
		}
		cout<<anss<<"\n";
	}
	return 0;
}