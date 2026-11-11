#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],s[M];
struct str
{
	int f,t;
}st[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int q=1;q<=n;q++)
	{
		for(int i=q;i<=n;i++)
		{
			if(st[a[i]].f==1)
			{
				for(int j=st[a[i]].t+1;j<i;j++)
				{
					if(st[a[j]].t<st[a[i]].t+1)
					{
						continue;
					}
					st[a[j]].f=0;
					st[a[j]].t=0;
				}
			}
			else
			{
				st[a[i]].f=1;
				st[a[i]].t=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(st[i].f==1)
			{
				s[i]++;
			}
			st[i].f=0;
			st[i].t=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s[i]<<' ';
	}
	return 0;
}