#include <bits/stdc++.h> 
using namespace std;
int n,ans,ansj;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		long long sm=0;
		ansj=1;
		for(int j=1;j<i;j++)
		{
			if(sm-a[j]+a[i]>m) continue;
			else 
			{
			    sm=sm-a[j]+a[i];
			    ansj++;
			}
		}
		ans=max(ans,ansj);
	}
	cout<<ans<<endl;
	return 0;
}
