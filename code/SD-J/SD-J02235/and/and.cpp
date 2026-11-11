#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m>2)
	{
		cout<<a[m];	
	}
	else
	{
		if(m==1)
		{
			cout<<a[1];
		}
		else
		{
			int maxn=-1;
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if((a[i]&a[j])>maxn)
					{
						maxn=(a[i]&a[j]);
					}
				}
			}
			cout<<maxn;
		}
	}
	return 0;
}
