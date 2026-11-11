#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510000],l[510000],k[510000],dp[510000],sum,sum1,ans,b[510000],kk=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
//	l[1]=0,k[1]=0,b[1]=0;
//	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1],l[i]=l[i-1]+b[i],k[i]=k[i-1]+l[i];
//	for(int i=1;i<=n;i++) cout<<l[i]<<" ";
//	cout<<endl; 
	int q=1;
	for(int i=1;i<=n;i++) 
	{
		long long qq=(a[i]-kk)*sum;
		if(ans+qq<=m) ans+=qq,sum++,sum1=max(sum1,sum),kk=a[i];
		 else
		 { 
		 	while(ans+qq>m&&ans>=0&&sum>=0&&q<i) ans-=kk-a[q],q++,sum--,qq=(a[i]-kk)*sum;
//			long long o=m-ans;
//			o/=(a[i]-kk);
//			sum=o; 
		 	sum++;
		 	sum1=max(sum1,sum);
		 }
//		cout<<ans<<" "<<sum<<" "<<sum1<<endl;
	}
	sum1=max(sum1,sum);
	cout<<sum1;
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/
