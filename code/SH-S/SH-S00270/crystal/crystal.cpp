#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,tot,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int a[n+10];
	for(ll i=0; i<n; i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=0; i<n; i++)
	{
		for(ll j=i; j<n; j++)
		{	
			tot=0;
			for(int k=i; k<j; k++)
			{
				tot+=a[j]-a[k];
				if(tot<=m)
				{
					ans=max(ans,j-i+1);
				}
			}
		}

	}
	cout<<ans;
	return 0;
}
