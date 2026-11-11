#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m,a[N],ans,dcs;
bool yes=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	stable_sort(a+1,a+n+1);
	dcs=a[2]-a[1];
	for(ll i=3;i<=n;i++)
		if(a[i]-a[i-1]!=dcs)
		{
			yes=0;
			break;
		}
	if(yes)
	{
		for(ll i=1;i<=n;i++)
			if(i*(dcs+dcs*i)/2>m)
			{
				cout<<i-1;
				return 0;
			}
		cout<<n;
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		ll uid=upper_bound(a+1,a+n+1,a[i])-a;
		ll can=m,num=uid-i;
		for(ll j=i-1;j>=1;j--)
		{
			can-=a[i]-a[j];
			if(can<0) break;
			num++;
		}
		ans=max(ans,num);
		i=uid-1;
	}
	cout<<ans;
	return 0;
}
/*
O(n^2)           #1~9    45pts
O(n^2)           #10~12? 15pts
tepan O(n log n) #13~18  30pts
^^^^^^^^^[75,90]pts^^^^^^^^^^^

5 12
2 5 8 11 14
*/
