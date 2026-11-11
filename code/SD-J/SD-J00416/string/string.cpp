#include <bits/stdc++.h>
using namespace std;
long long ans,n;
bool flag;
struct node
{
	long long m;
	char c;
};
node a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].m >> a[i].c;
		if(a[i].c!=a[i-1].c && i!=1)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>i;j--)
			{
				if(j==i)
				{
					cout << ans;
					return 0;
				}
				if(a[i].c!=a[j].c)
				{
					if(a[i].m>a[j].m)
					{
						a[i].m-=a[j].m;
						ans+=a[j].m;
						a[j].m=0;
					}
					else
					{
						ans+=a[i].m;
						a[i].m=0;
						a[j].m-=a[i].m;
					}
					if(a[j].m==0)
					{
						n--;
					}
					if(a[i].m==0)
					{
						break;
					}
				}
				else
				{
					if(a[i].m>a[j].m)
					{
						a[i].m-=a[j].m;
						a[j].m=0;
					}
					else
					{
						a[j].m-=a[i].m;
						a[i].m=0;
					}
					if(a[j].m==0)
					{
						n--;
					}
					if(a[i].m==0)
					{
						break;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
