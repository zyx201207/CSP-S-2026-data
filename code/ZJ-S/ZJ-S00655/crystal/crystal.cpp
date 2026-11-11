#include<iostream>
#include<algorithm>
#define Max 500005
namespace my
{
	using std::cin;
	using std::ios;
	using std::max;
	using std::sort;
	using std::cout;
}
using namespace my;
int n,ans;
unsigned long long m;
long long a[Max];
long long sum[Max];
int up(int start,int now,int cost)
{
	long long will_cost=(sum[now]-sum[now-1])*(now-start);
	if(cost+will_cost>m)
		return now-start;
	else
	{
		up(start,now+1,cost+will_cost);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i)
	{
		sum[i]=a[i]-a[1];
	}
	for(int i=1;i<n;++i)
	{
		ans=max(ans,up(i,i+1,0));	
	}
	cout<<ans;
	return 0;
}
