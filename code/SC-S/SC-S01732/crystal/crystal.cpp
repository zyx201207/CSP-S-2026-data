#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[500005];
ll dif[500005];

int  main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++)
		dif[i]=a[i+1]-a[i];
	ll l=1;
	int duan=0;
	ll mx=0;
	while(l<=n-1)
	{
		ll cnt=1;
		ll sum=0;
		for(;l<=n-1;l++)
		{
			sum+=dif[l]*(l-duan);
			if(sum>m) 
			{
				duan=l;
				break;
			}
			cnt++;
			
		}
		mx=max(mx,cnt);
		l++;
	}
	cout<<mx;
	return 0;
}