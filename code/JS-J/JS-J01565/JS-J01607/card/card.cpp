#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500011];
ll last[500011];
bool f[500011];
ll t[500011];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=k;i<=n;i++)
		{
			if(!last[a[i]])
			{
				last[a[i]]=i;
			}
			else
			{
				for(ll j=last[a[i]];j<i;j++)
				{
					last[a[j]]=0;
					f[j]=true;
				}
				last[a[i]]=i;
			}
		}
		for(ll i=k;i<=n;i++)
		{
			if(!f[i])
			{
				t[a[i]]++;
			}
			f[i]=false;
			last[a[i]]=0;
		}
	}
	for(ll i=1;i<=m;i++)
		cout<<t[i]<<" ";
	return 0;
}
