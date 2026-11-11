#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,sum,a[100005],j,maxn;
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
	{
		if(maxn>sum)
		 maxn=sum;
		sum=0;
		for(j=n-1;j>=1;j--)
		{
			if(a[i]-a[j]>m)
			 break;
			else
			{
			 m-=a[i]-a[j];
			 sum++;
			}
		}
	}
	cout<<maxn;
	return 0;
}
