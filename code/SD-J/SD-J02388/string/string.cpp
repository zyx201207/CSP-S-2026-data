#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int l=1,r=n;
	long long sum=0;
	long long tongji=0;
	while(l<r)
	{
		sum=max(a[l],a[r])-min(a[l],a[r]);
		if(b[l]!=b[r])
		{
			tongji+=min(a[l],a[r]);
		}
		if(a[l]>a[r])
		{
			a[l]=sum;
			r--;
		}
		else if(a[l]<a[r])
		{
			a[r]=sum;
			l++;
		}
		else if(a[l]==a[r])
		{
			l++;
			r--;
		}
	}
	cout<<tongji;
	return 0;
 }
