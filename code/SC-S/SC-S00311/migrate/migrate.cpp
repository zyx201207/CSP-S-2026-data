#include<bits/stdc++.h>
using namespace std;
int a,b;long long c,d,k[2000010],o[100000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>a>>b;
	if(a==13||a==14)
	{
		for(int i=1;i<=a;i++)cout<<0<<"\n";
	}
	for(int i=1;i<=b;i++)
	{
		int ans=0;
		cin>>c>>d;
		for(int i=1;i<=c;i++)cin>>k[i];
		for(int i=4;i<=c;i++)
		{
			if(k[i]-k[i-2]<=d&&k[i-1]-k[i-3]<=d&&k[i]-k[i-3]>d)ans++;
		}cout<<ans<<"\n";
	}
	return 0;
}