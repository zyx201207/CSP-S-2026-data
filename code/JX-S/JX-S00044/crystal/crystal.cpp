#include<bits/stdc++.h>
using namespace std;
int n;long long m,a[500010],now,ans;
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
	long long rt=1;
	for(int i=1;i<=n;i++)
	{
		while((a[rt+1]-a[rt])*(rt+1-i)+now<=m&&rt<n)
		{
			rt++;
			now+=(a[rt]-a[rt-1])*(rt-i);
		}
		ans=max(ans,rt-i+1);
		now-=(a[rt]-a[i]);
	}
	cout<<ans;
	return 0;
}
