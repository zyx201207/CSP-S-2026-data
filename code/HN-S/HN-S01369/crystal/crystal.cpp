#include<bits/stdc++.h>
using namespace std;
const int N=5*100005;
int n,l=1,ans[5],p=90;
long long m,a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) p=0;
	}
	if(p==0)
	{
		sort(a+1,a+n+1);
		ans[1]=1;
		for(int i=n;i>=1;i--)
		{
			for(int j=i-1;j>=1;j--)
			{
				sum[l]+=(a[i]-a[j]);
				ans[1]++;
				if(sum[l]>m){
					ans[1]-=1;
					sum[l]=0;
					ans[2]=max(ans[1],ans[2]);
					ans[1]=1;
				}
				else
					if(sum[l]==m||j==1)
					{
						sum[l]=0;
						ans[2]=max(ans[1],ans[2]);
						ans[1]=1;
					}
			}
			ans[1]=1;
		 }
		 cout<<ans[2];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			sum[1]+=i;
			if(sum[1]==m)
			{
				cout<<i+1;
				return 0;
			}
			else
			if(sum[1]>m)
			{
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
 } /*5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
6 5
7 6 3 5 4 6
*/
