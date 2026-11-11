#include<bits/stdc++.h>
using namespace std;
const long long lu=1e8+10;	
long long a[lu];
int sum=-10,sum1=1;
int cnt=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int cnt=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<long long>());
	
	
	for(int i=1;i<n;i++)
	{
		int ans=i;
		cnt=m;
		sum1=1;
		for(int j=1;j<=n-j-1;j++)
		{
			if(ans!=1 && a[ans]==a[ans-1])
			{
				continue;
			}
			if(cnt<=0)
				{
					break;
				}
			if(cnt>a[ans]-a[ans+j])
			{
				cnt=cnt -(a[ans]-a[ans+j]);
				if(cnt>=0)
				sum1++;
			}
			
		}
		sum=max(sum,sum1);	
	}
	cout<<sum;
	return 0;
}
