#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500000+10],b[500000+10],ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long cnt=1,x=m,l=i-1;
		while(x>0)
		{
			if(x>=a[i]-a[l]&&l>0)
			{
				cnt++;
				x-=a[i]-a[l];
				l--;
			}
			else
			{
				x=-1;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}