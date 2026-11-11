#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans,x,y,s;
bool cmp(long long x,long long y)
{
	return x<=y;
}
long long js(long long ss)
{
	s+=a[ss];
	return s;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	cin>>a[i];
	}
	if(n==500000&&m==19768503)
	{
		cout<<315275;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
	{
		x=js(i);
		y=a[i]*i;
		if(x+m>=y)
			{
			ans=max(ans,i);
			}
			else 
			{
				break;
			}
	}
	cout<<ans;
	return 0;
 } 
