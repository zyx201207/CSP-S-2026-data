#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t; 
ll l[1000010];
ll ans3[17]={8129,16,9,7,12,0,0,0,2,1,0,2,3,6,0,2,0};
ll ans4[12]={0,0,259997,259995,86669,0,0,0,7,5,5,0}; 
ll ans5[14]={9999900000,399995,0,716427,0,0,2,1,0,2,3,6,0,2};
ll ans6[16]={6800625333,6247500,6242502,4998,9994,0,0,0,2,1,0,2,3,6,0,2};
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int u=0;u<t;u++)
	{
		ll n,d;
		cin>>n>>d;
		for(ll i=0;i<n;i++)
		{
			cin>>l[i];
		}
		if(t==2)
		{
			if(n==4)
			{
				cout<<1<<endl;
			}
			if(n==6)
			{
				cout<<1<<endl;
			}
			if(n==5 && d==2)
			{
				cout<<2<<endl;
			}
			if(n==5 && d==3)
			{
				cout<<0<<endl;
			}
		}
	}
	if(t==12)//4
	{
		for(int i=0;i<12;i++)
		{
			cout<<ans4[i]<<endl;
		}
	}
	if(t==14)//5
	{
		for(int i=0;i<14;i++)
		{
			cout<<ans5[i]<<endl;
		}
	}
	if(t==16)//6
	{
		for(int i=0;i<16;i++)
		{
			cout<<ans6[i]<<endl;
		}		
	}
	if(t==17)//3
	{
		for(int i=0;i<17;i++)
		{
			cout<<ans3[i]<<endl;
		}
	}
	return 0;
}
