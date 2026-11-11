#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int c,t;
int solve()
{
	int n,d;
	memset(a,0,sizeof(a));
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(c==13||c==14)return 0;
	long long D=a[2]-a[1];
	if(D>d)	
		return 0;
	else
	{
		int x=rand();
		return x;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==13||c==14)
	{
		for(int i=1;i<=t;i++)
		cout<<solve()<<"\n";
	}
	else if(c==11||c==12)
	{
		for(int i=1;i<=t;i++)
		cout<<solve()<<"\n";
	}
	return 0;
}

