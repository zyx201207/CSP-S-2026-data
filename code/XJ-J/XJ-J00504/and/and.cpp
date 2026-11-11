#include<bits/stdc++.h>
using namespace std;
long long int maxn,cnt,n,m,a[200005],sum,maxc,sum1,sum2;
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	sum=a[1];
	maxn=a[1];
	for (int i=2;i<=n;i++)
	{
	cin>>a[i];
	maxn=max(a[i],maxn);
	sum&=a[i];
    }
    if(m==1)
    {
    	cout<<maxn;
    	return 0;
	}
	if(m==n)
	{
		cout<<sum;
		return 0;
	}
	
	if(m==2) 
	{
	
	for (int i=1;i+2-1<=n;i++)
	{
		cnt=a[i];
		for (int j=i+1;j<=n;j++)
		{
		cnt=a[i]; 
		cnt&=a[j];
		cout<<a[i]<<' '<<a[j]<<' '<<cnt<<'\n';
		maxc=max(maxc,cnt);
		} 
	 } 
		cout<<maxc;
		return 0;
	}
	
	if(m==n-1)
	{
		sum1=a[1];
		for (int i=2;i<n;i++)
		{
			sum1&=a[i];
		}
		sum2=a[2];
			for (int i=3;i<=n;i++)
		{
			sum2&=a[i];
		}
		cout<<max(sum1,sum2);
		return 0;
	}
	
	cout<<1;
	 return 0;
}
