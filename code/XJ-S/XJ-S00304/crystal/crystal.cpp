#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[500010];//水晶的价值
ll m;//操作次数
ll n;//水晶量 
ll ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int oo=1;//判断是否等差 
	ll cha=0; //等差的差 
	for(ll i=0;i<n;i++)
	{
		cin>>v[i];
		if(i==1)
		{
			cha=v[i]-v[i-1];
		}
		if((v[i]-v[i-1])!=cha)
		{
			oo = 0;
		}
	}
 	if(oo)//特判 等差 
 	{
 		ll u=0;
 		ll i=1;
 		for(i;i<m;i++)
 		{
 			if(u+i*cha<=m)
 			{
 				u+=i*cha;
			}
 			else
 			{
 				i--;
 				break;
			}
 			
		}
 		ans+=i;
 		cout<<ans;
 		return 0;
	}
	sort(v,v+n);
	ll r=0; 
	for(ll i=n-1;i>=r;i--)
	{
		int pan=1;//判断次数用完了没 
		ll ling=0;//储存次数 
		ll c=0;//储存已改变宝石（包括本宝石） 
		for(ll a=i;a>=0;a--)
		{
			ling+=v[i]-v[a];
			if(ling<=m)
			{
				c++;
			}
			else
			{
				pan=0;
				break;
			}
		}
		if(c>ans)
		{
			ans=c;
			r=c-1;
		}
	}
	cout<<ans;
	return 0;
}
//15:49版本 
