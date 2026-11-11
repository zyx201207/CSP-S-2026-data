#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0;
	int ans=0;
	for (int l=1,r=2;r<=n;r++)
	{
		sum+=(a[r]-a[r-1])*(r-l);
		if(sum>m)
		{
			ans=max(ans,r-l);
			while(sum>m)
			{
				sum-=(a[r]-a[l]);
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}