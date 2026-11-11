#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+10;
const int M=5e5+10;
int n,m;
int a[M],b[N],c[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			int flag=0;
			if(b[a[j]]==1) 
			{
				for(int t=j-1;t>=i;t--)
				{
					if(a[t]==a[j])
					{
						flag=t;
						break;
					}
				}
				for(int t=flag;t<=j;t++)
				{
					b[a[t]]=0;
				}
			}
			b[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			c[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}









