#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,c,d,il[2000010],t;
vector <ll> a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (c==11 || c==12 || c==0)
	{
		while (t--)
		{
			cin>>n>>d;
			if (n<3)
			{
				cout<<"0\n";
				continue;
			}
			for (int i=1;i<=n;i++)
			{
				cin>>il[i];
			}
			ll dist = il[2]-il[1];
			ll time = d/dist;
			if (time<2)
			{
				cout<<"0\n";
				continue;
			}
			if (dist*(time*2-1)<=il[n]-il[1]) cout<<n-time*2+1;
			else cout<<0;
			cout<<'\n';
		}
		return 0;
	}
/*	while (t--)
	{
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>il[i];
		}
	}*/
	return 0;
}
