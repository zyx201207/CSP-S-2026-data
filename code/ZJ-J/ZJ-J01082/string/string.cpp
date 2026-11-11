#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
	long long x;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	long long half=sum/2;
	if(sum%2==1) half++;
	long long cnt=0;
	long long sum_l=0,sum_r=0;
	for(int i=1,j=n;i<=n&&j>=1;)
	{
		if(i>=j) break;
		if(sum_l+a[i].x>half)
		{
			a[i].x=a[i].x-2*(a[i].x-half);
			if(sum%2==1) a[i].x--;
		}
		if(sum_l+a[i].x==half)
		{
			if(sum%2==1) a[i].x--;
		}
		if(sum_r+a[j].x>half)
		{
			a[j].x=a[j].x-2*(a[j].x-half);
			if(sum%2==1) a[j].x--;
		}
		if(sum_r+a[j].x==half)
		{
			if(sum%2==1) a[j].x--;
		}
		if(a[i].c==a[j].c)
		{
			if(a[i].x<a[j].x)
			{
				sum_l+=a[i].x;
				sum_r+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}
			else if(a[i].x==a[j].x)
			{
				sum_l+=a[i].x;
				sum_r+=a[i].x;
				i++,j--;
			}
			else
			{
				sum_l+=a[j].x;
				sum_r+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}
		}
		else
		{
			if(a[i].x<a[j].x)
			{
				cnt+=a[i].x;
				sum_l+=a[i].x;
				sum_r+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}
			else if(a[i].x==a[j].x)
			{
				cnt+=a[i].x;
				sum_l+=a[i].x;
				sum_r+=a[i].x;
				i++,j--;
			}
			else
			{
				cnt+=a[j].x;
				sum_l+=a[j].x;
				sum_r+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}