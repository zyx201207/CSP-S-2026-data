#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int n,m,a[500001];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=1)now+=(a[i]-a[i-1])*(i-l);
		while(now>m)
		{
			now-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
}