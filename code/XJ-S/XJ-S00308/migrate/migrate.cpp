#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
typedef long long ll;
ll a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ll n;
		ll d;
		cin>>n>>d;
		bool flaga=true,flagb=true,flagc=true;
		ll aaa=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i==2) aaa=a[i]-a[i-1];
			if(i>=2)
			{
				if(a[i]-a[i-1]!=aaa) flaga=false;
			}
		}
		
		if(n<=3)
		{
			cout<<"0"<<"\n";
			continue;
		}
		if(flaga)
		{
			d=d/aaa;
			if(d<=1||d>=n) cout<<"0"<<"\n";
			else cout<<n-d*2+1<<"\n";
			continue;
		}
		cout<<'0'<<"\n";
	}
	return 0;
}
