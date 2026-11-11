#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx,cnt,ans;
struct num
{
	long long a,s;
} nu[1000000]; 
int cmp(num x,num y)
{
	return x.s>y.s;
}
int main()
{
	//=========================================
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> nu[i].a;
		maxx=max(maxx,nu[i].a);
	}
	for(int i=1;pow(2,i)<=maxx;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(nu[j].a%2==0)
			{
				cnt++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(nu[j].a%2==0)
			{
				nu[j].s+=cnt;
			}
		}
	}
	sort(nu+1,nu+n+1,cmp);
	ans=nu[1].a;
	for(int i=2;i<=m;i++)
	{
		ans&=nu[i].a;
	}
	cout << ans;
	return 0;
} //极限卡点4分钟交！！！ 
