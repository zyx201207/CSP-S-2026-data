#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long ans=0;
	for(int i=31;i>=0;i--)
	{
		long long ma=ans|(1LL<<i);
		int cnt=0;
		for(int x:a)
		{
			if((x&ma)==ma)
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans=ma;
		}
	}
	cout<<ans;
	return 0;
}
