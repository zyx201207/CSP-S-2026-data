#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans,x,s;
bool b=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			b=0;
		}
	}
	if(b)
	{
		for(ll i=1;i<=n;i++)
		{
			if(m<(i*i+i)/2)
			{
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		for(ll l=1;l<=n;l++)
		{
			if(l>ans)
			{
				for(ll r=l;r<=n;r++)
				{
					if(r-l+1>ans)
					{
						x=0;
						for(ll i=l;i<r;i++)
						{
							x+=a[r]-a[i];
						}
						if(x<=m)
						{
							ans=r-l+1;
						}
						if(ans==n)
						{
							cout<<ans;
							return 0;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

