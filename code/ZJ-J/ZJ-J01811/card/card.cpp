#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],t[500010],ans[300010];
bool b[300010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=0;
		memset(b,0,sizeof b);
		for(ll j=i;j<=n;j++)
		{
			if(!b[a[j]])
			{
				l++;
				t[l]=a[j];
				b[a[j]]=1;
			}
			else
			{
				while(t[l]!=a[j]&&l>1)
				{
					b[t[l]]=0;
					l--;
				}
			}
		}
		for(ll j=1;j<=l;j++)ans[t[j]]++;
	}
	for(ll i=1;i<=m;i++)
	{
		cout<<ans[i];
		if(i==m)cout<<'\n';
		else cout<<' ';
	}
	return 0;
}