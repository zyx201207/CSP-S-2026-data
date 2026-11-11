#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,k;
	cin>>n>>k;
	long long a[n],sum[n+1];
	sum[0]=0;
	for(long long i=1;i<=n;i++)
	{
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
			//cout<<sum[i]<<endl;
	}
	long long ans=1;
	sort(a+1,a+1+n);
	long long l=1;
    for(long long i=1;i<=n;i++)
	{
       while(l<i)
        {
     	if(a[i]*(i-l+1)<=sum[i]-sum[l-1]+k)break;
     	else l++;
	    }
	 //  cout<<l<<endl;
	 ans=max(ans,i-l+1);
	}	
	cout<<ans;
}
//1 2 4 8 9
//1 3 7 15 24