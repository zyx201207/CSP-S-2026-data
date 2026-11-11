#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cy[500005];
long long sum=1;	
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long  i=1;i<=n;i++)
	{
		cin>>cy[i];
	}
	sort(cy+1,cy+n+1);
	for(long long  i=2;i<=n;i++)
	{
		long long cnt=1;
		long long p=m;
		for(long long j=i-1;j>=1;j--)
		{
			if(p-cy[i]+cy[j]>=0)
			{
				p=p-cy[i]+cy[j];
				cnt++;
			}
			else
			break;
		}
		sum=max(sum,cnt);
	}	
	cout<<sum<<endl;
	return 0;
}
