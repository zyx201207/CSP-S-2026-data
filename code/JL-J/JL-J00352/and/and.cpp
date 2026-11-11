#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	
	long long ans = 0;
	
	for(long long i = 30;i >= 0;i--)
	{
		long long tmp = ans | (1LL << i);
		long long cnt = 0;
		for(long long j = 0;j < n;j++)
		{
			if((a[j] & tmp) == tmp)
			{
				cnt++;
			}
		}
		if(cnt >= m)
			ans = tmp;
	}
	
	cout<<ans<<"\n";

	return 0;
}
