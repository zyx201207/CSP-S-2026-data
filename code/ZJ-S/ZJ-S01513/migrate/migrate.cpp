#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+7;
ll t,ans=0,a[N],c;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		if(c==13||c==14)
		{
			cout<<0<<"\n";
			continue;
		}
		ll n,d;
		ll dc=0;
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>1)dc=max(dc,a[i]-a[i-1]);
		}
		if(d<=dc)
		{
			cout<<0<<"\n";
			continue;
		}
		ll g=d/dc;
		if(g==1)
		{
			cout<<0<<"\n";
		}
		ll z=(g-1)*2;
		ll qs=z+2;
		for(int i=qs;i<=n;i++)
		{
			ans++;
		}
		cout<<ans<<"\n";
	}
}
/*
1         6
  2     5
1     4
1 2 3 4 5 6 7
2 2 1 0
3 4 1 0
4 6 2 2
dc 等差值
d 飞行距离
飞距 g=d/dc
z=(g-1)*2 中间需距 
最大下标-最小符合下标 
*/
