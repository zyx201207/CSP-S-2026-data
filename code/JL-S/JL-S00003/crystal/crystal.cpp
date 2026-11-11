#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long cs[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	long long n,m;
	int maxc=0;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++)
	{
		cin>>cs[i];
	}
	sort(cs,cs+n);
	for(int i=n-1;i>=0;i--)
	{
		long long sum=0;
		int j=0,cnt=0;
		for(;j<=i;j++)
		{
			sum+=cs[i]-cs[j];
			cnt++;
		}
		if(sum<=m)
		{
			maxc=max(maxc,cnt);
			break;
		}
		for(j=0;sum>m;j++)
		{
			sum-=(cs[i]-cs[j]);
			cnt--;
		}
		maxc=max(maxc,cnt);
	}
	printf("%d\n",maxc);
	return 0;
}

