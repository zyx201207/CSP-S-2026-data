#include<bits/stdc++.h>
using namespace std;
long long sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long m,n,dq,ji=1,ma=1,li;
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>sum[i];
	sort(sum+1,sum+n+1);
	if(n>5000)
	{
		ji=1,li=m,dq=sum[n];
		for(int o=n-1;o>=1;o--)
		{
			if(sum[o]==dq)
			{
				ji++;
				if(ji>ma) ma=ji;
				continue;
			}
			if(li>=sum[n]-sum[o])
			{
				ji++;
				if(ji>ma) ma=ji;
			}
			li-=sum[n]-sum[o];
			if(li<0) break;
		}
		cout<<ma;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
	for(int i=n;i>=ma;i--)
	{
		ji=1,li=m,dq=sum[i];
		for(int o=i-1;o>=1;o--)
		{
			if(sum[o]==dq)
			{
				ji++;
				if(ji>ma) ma=ji;
				continue;
			}
			if(li>=sum[i]-sum[o])
			{
				ji++;
				if(ji>ma) ma=ji;
			}
			li-=sum[i]-sum[o];
			if(li<0) break;
		}
	}
	cout<<ma;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
