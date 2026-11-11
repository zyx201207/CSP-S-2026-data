#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll c,T,n,d,x[2000005];
void solve1()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	ll cha=x[2]-x[1];
	if(cha>d||cha>x[n])
	{
		cout<<0<<endl;
		return;
	}
	ll len=x[2]-x[1];
	ll bl=d/len;
	if(bl==1)
	{
		cout<<0<<endl;
		return;
	}
	ll sum=floor(n/bl),sh=n-(bl*sum);
	ll ans=sh;
	ans+=(sum-1)*(bl-1);
	cout<<ans<<endl; 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		solve1();
	} 
	return 0;
}
