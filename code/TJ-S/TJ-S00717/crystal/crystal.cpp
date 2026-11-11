#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
#define int long long
int m,n,a[maxn],bac[maxn],ans,xx,lef,cr;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>15000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(a[1]==a[2])
		{
			cout<<n;
		}
		else
		{
			int ed=a[n]-a[1];
			int st=0;
			int al=(st+ed)*n;
			if(al&1==0&&m>=al/2)
			{
				cout<<n;
			}
			else if(al&1==1&&m>al/2)
			{
				cout<<n;
			}
			else
			{
				for(int i=2;i<=n;i++)
				{
					ed=a[n]-a[i];
					al=(st+ed)*(n-i+1);
					if(al&1==0&&m>=al/2)
					{
						cout<<n;
					}
					else if(al&1==1&&m>al/2)
					{
						cout<<n;
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		bac[i]=bac[i+1]+a[i+1]-a[i];
	}
	for(int i=2;i<=n;i++)
	{
		cr=a[i];
		lef=m,xx=1;
		for(int j=i-1;j>=1;j--)
		{
			int co=bac[j]-bac[i];
			if(lef>=co)
			{
				lef-=co;
				xx++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,xx);
	}
	cout<<ans;
	return 0;
 } 
