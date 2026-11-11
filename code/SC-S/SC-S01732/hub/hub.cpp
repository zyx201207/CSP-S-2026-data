#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll a[500005];
ll dif[500005];

int  main()
{
	//马菡我aini
	freopen("crystal.in","r".stdin);
	freopen("crystal.out","w".stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-1;i++)
		dif[i]=a[i+1]-a[i];
	//for(int i=1;i<=n;i++)
		//cout<<a[i]<<" ";
	//int b=0;
	//sort(dif+1,dif+1+n);
	ll l=1;
	int duan=0;
	ll mx=0;
	while(l<=n-1)
	{
		ll cnt=0;
		ll sum=0;
		for(;l<=n-1;l++)
		{
			//cout<<l<<" ";
			//cout<<dif[l]<<" ";
			cnt++;
			//cout<<cnt<<" ";
			//if(sum>=m) 
			//{
				//duan=l;
				//break;
			//}
			if(cnt==313325) cout<<sum<<" ";
			sum+=dif[l]*(l-duan);
			//cout<<sum<<" ";
			//cout<<"\n";
			
		}
		//cout<<"\n";
		//cout<<l<<"\n";
		//cout<<cnt<<"\n";
		mx=max(mx,cnt);
		l++;
		//cout<<sum<<"\n";
		//cout<<cnt<<"\n";
		//cout<<l<<"\n";
		cout<<dif[313324];
	}
	//cout<<"\n";
	//cout<<mx;
	//cout<<"\n";
	//cout<<cnt;
	//cout<<mx;
	
	return 0;
}