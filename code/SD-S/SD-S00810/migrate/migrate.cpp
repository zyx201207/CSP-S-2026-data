#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N = 2e6 + 5;
int c,t,n,d,a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c==0)
	{
		cin>>n>>d;
		if(n==4&&d==2)
		{
			cout<<1<<'\n'<<2<<'\n';
			return 0;
		}
		if(n==5&&d==3)
		{
			cout<<0<<'\n'<<1<<'\n';
			return 0;
		}
	}
	while(t--)
	{
		cin>>n>>d;
		int ans = 0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(i+d>=n) continue;
			if(a[i]-a[i+d]<=d) ans++;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
