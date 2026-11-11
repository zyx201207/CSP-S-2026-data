#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int mm=m;
		int ans2=0;
		if(a[i]==a[i+1]&&i!=n)
			continue;
		for(int j=i;j>=1&&mm>0;j--)
		{
			mm-=(a[i]-a[j]);
			ans2++;
		}
		if(mm<0)
			ans2--;
		ans=max(ans2,ans);
	}
		
	cout<<ans;
	return 0;
}

