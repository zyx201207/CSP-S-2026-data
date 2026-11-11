#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[500005],b[500005],c[500005];
long long cnt=1,k=0;
bool f=true;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			f=false;
		}
	}
	if(f)
	{
		for(int i=2;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				cnt++;
			}
			else
			{
				k+=cnt;
				cout<<k<<" ";
				cnt=1;
			}
		}
		cout<<k+cnt;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			t=0;
			for(int j=i;j<=n;j++)
			{
				t++;
				b[t]=a[j];
				for(int l=1;l<t;l++)
				{
					if(b[l]==b[t])
					{
						t=l;
						break;
					}
				}
			}
			for(int j=1;j<=t;j++)
			{
				c[b[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<c[i]<<" ";
		}
	}
	return 0;
} 
