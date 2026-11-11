#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
	int num;
	char k;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].k;
	}
	long long l=1,r=n,ans=0;
	while(l<=r)
	{
		if(a[l].num>=a[r].num)
		{
			int sum=a[l].num,sum1=a[r].num;
			if(a[r].k==a[l].k)
			{
				sum-=a[r].num;
			}
			while(a[l].num>sum1&&l<=r)
			{
				r--;
				sum1+=a[r].num;
				if(a[r].k==a[l].k)
				{
					sum-=a[r].num;
				}
			}
			a[r].num=sum1-a[l].num;
			if(a[r].k==a[l].k)
			{
				sum+=a[r].num;
			}
			l++;
//			cout<<sum<<endl;
			ans+=sum;
		}
		if(a[l].num<a[r].num)
		{
			int sum=a[r].num,sum1=a[l].num;
			if(a[r].k==a[l].k)
			{
				sum-=a[l].num;
			}
			while(a[r].num>sum1&&l<=r)
			{
				l++;
				sum1+=a[l].num;
				if(a[l].k==a[r].k)
				{
					sum-=a[l].num;
				}
			}
			a[l].num=sum1-a[r].num;
			if(a[r].k==a[l].k)
			{
				sum+=a[l].num;
			}
			r--;
			ans+=sum;
		}
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}


 
