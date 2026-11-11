#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0,sum,cnt,cd,cntnl=0,cntd=0,cznt=0,cfnt=0;
ll a[1000010],b[1000010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==i)
		{
			cnt++;
		}
	}
	sort(a+1,a+1+n);
		for(int i=1;i<=n-1;i++)
		{
			b[i]=a[n]-a[n-i];
		}
		for(int i=1;i<=n;i++)
		{
			if(cntnl>m)
			{
				ans--;
				break;
			}
			else if(cntnl==m)
			{
				cout<<ans+1;
				return 0;
			}
			else
			{
				cntnl+=b[i];
				ans++;
			}
		}
		cout<<ans+1;
		return 0;
	/*else if(cntd==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0||a[i]==0)	cznt++;
			else if(a[i]<0)	cfnt++;
		}
		if(cznt==n)
		{
			for(int i=1;i<=n-1;i++)
			{
				b[i]=a[n]-a[n-i];
			}
			for(int i=1;i<=n;i++)
			{
				if(cntnl>m)
				{
					ans--;
					break;
				}
				else if(cntnl==m)
				{
					cout<<ans+1;
					return 0;
				}
				else
				{
					cntnl+=b[i];
					ans++;
				}
			}
			cout<<ans+1;
			return 0;
		}
	}*/
}
