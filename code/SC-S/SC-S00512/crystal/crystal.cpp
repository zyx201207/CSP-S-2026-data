//freopen!!
//only output!! 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int tail=1,sum=0,now=1,ans=0;
	for(;now<=n;now++)
	{
		sum+=(a[now]-a[now-1])*(now-tail);
		while(sum>m)
		{
			sum-=(a[now]-a[tail]);
			tail++;
		}
		ans=max(ans,now-tail+1);
	}
	cout<<ans;
	return 0;
}