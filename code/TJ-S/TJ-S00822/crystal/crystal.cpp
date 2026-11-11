#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0,n;
	long long m;
	vector<long long> a;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		long long c;
		cin>>c;
		a.push_back(c);
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]==a[i+1])
		{
			continue;
		}
		long long m1=m;
		int cnt=0;
		for(int j=i-1;j>=0;j--)
		{
			if(m1-(a[i]-a[j])>=0)
			{
				m1-=(a[i]-a[j]);
				cnt++;
			}
		}
		ans=max(ans,cnt+1);
		if(ans>=n-(n-i))
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
