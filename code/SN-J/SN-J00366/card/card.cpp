#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500001],ans[300001],cs[300001][3];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		memset(cs,0,sizeof(cs));
		for(ll j=i;j<=n;j++)
		{
            cs[a[j]][1]++;
            if(cs[a[j]][1]>1)
            {
            	for(ll k=cs[a[j]][2];k<j;k++)
            	{
            		cs[a[k]][1]--;
            		if(cs[a[k]][1]<0) cs[a[k]][1]++;
				}
			}
			cs[a[j]][2]=j;
		}
		for(ll j=1;j<=m;j++)
		{
			ans[j]+=cs[j][1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
