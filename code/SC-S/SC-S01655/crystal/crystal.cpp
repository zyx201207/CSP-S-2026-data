#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000010],x[1000010],sum,ans,cnt,lst=2,sum2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		x[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		cnt++;
		sum+=x[i]*cnt;
		sum2+=x[i];
		while(sum>m)
		{
			sum-=sum2;
			sum2-=x[lst];
			cnt--;
			lst++;
		}
		ans=max(ans,cnt+1);
	}
	cout<<ans;
	return 0;
}
