#include<bits/stdc++.h>
using namespace std;
int a[200005];
char f[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>f[i];
	}
	long long ans=0;
	int l=1,r=n;
	while(l<r)
	{
		if(f[l]!=f[r])
		{
			int gh=min(a[l],a[r]);
			ans+=gh;
			a[l]-=gh;
			a[r]-=gh;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else
		{
			int gh=min(a[l],a[r]);
			a[l]-=gh;
			a[r]-=gh;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}