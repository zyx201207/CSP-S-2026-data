#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,max_=0;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cnt;
	int j,ans;
	for(int i=1;i<=n;i++)
	{
		cnt=m;
		j=i-1;
		ans=1;
		while(j>=1)
		{
			int c=a[i]-a[j];
			if(c<=cnt)
			{
				cnt-=c;
				ans++;
				j--;
			}
			else
			{
				break;
			}
		}
		max_=max(max_,ans);
	}
	cout<<max_;
	
	return 0;
}