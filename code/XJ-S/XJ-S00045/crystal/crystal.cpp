#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,maxn=1;
ll m;
ll a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i < n;i++)
	{
		bool flag=true;
		int mn=m;
		for(int j = 1;j <= i;j++)
		{
			if(a[i]+mn>=a[i+1])mn-=a[i+1]-a[i];
			else 
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			for(int j = 1;j <= i;j++)
			{
				m-=a[i+1]-a[i];
				a[j]=a[i+1]; 
			}
			maxn=max(maxn,i+1);
		}
		if(m<=0)break;
	}
	cout<<maxn;
	return 0;
}
