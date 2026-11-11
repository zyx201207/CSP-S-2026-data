#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],cnt,ans;
long long m;
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,greater<int>());
	for(int k=1;k<=n;k++)
	{
		long long sum=m;
		cnt=0;
		for(int i=k;i<=n;i++)
		{
			sum-=(a[k]-a[i]);
			if(sum>=0)
			{
				cnt++;
			}
			else
				break;
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
	return 0;
}
