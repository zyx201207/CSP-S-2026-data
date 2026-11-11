#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int d[500005];
int sum[500005];
int summ[500005];
bool check(int x,int y)
{
	// 1 5 7 8
	//1 6 13 21
	//2 4
	if(x==y)
	return 1;
	int end=n-x;
	int start=n-y;
	int aaa=summ[end]-summ[start-1]-sum[start]*(y-x+1);
/*	cout<<summ[end]<<" "<<sum[start]<<endl;
	cout<<x<<" "<<y<<" "<<aaa<<endl;*/
	if(aaa<=m)
	return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
	{
		int num=n-i;
		d[num]=a[i+1]-a[i];
		sum[num]=sum[num-1]+d[num];
		summ[num]=summ[num-1]+sum[num];
	}
//	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)//right
	{
	//	cout<<"***";
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
			}
			else{
				l=mid+1;
			}	
		}
		//cout<<i<<" "<<l<<" "<<r<<endl;
		ans=max(i-l+1,ans);
	}
	cout<<ans;

	return 0;
 } 
