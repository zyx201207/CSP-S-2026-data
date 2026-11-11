//不管，就写贪心，不可能是DP,不对，好像是二分？？？ 好吧，不会正解
//mabey 80pts 
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
int a[500005];
int ans=0;
bool check(int mid)
{
	int maxn=1;
	int num=m;
	bool f=0;
	for(int i=mid-1;i>=1;i--)
	{
		if(num>=(a[mid]-a[i]))
		{
			maxn++;
			num-=(a[mid]-a[i]);
		}
		else
		{
			f=1;
			break;
		}
	}
	ans=max(ans,maxn);
	if(f)
	{
		return true;
	}
	else
	{
		return false;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int d=a[2]-a[1];
	bool f=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d)
		{
			f=0;
			break;
		}
	}
	if(n<=5000)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			int sum=1;
			int num=m;
			for(int j=i-1;j>=1;j--)
			{
				if(num>=(a[i]-a[j]))
				{
					sum++;
					num-=(a[i]-a[j]);
				}
				else
				{
					break;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	else if(f)
	{
		int num=m;
		int sum=1;
		for(int i=n-1;i>=1;i--)
		{
			if(num>=(a[n]-a[i]))
			{
				sum++;
				num-=(a[n]-a[i]);
			}
			else
			{
				break;
			}
		}
		cout<<sum;
	}
	else
	{
		ans=0;
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1; 
			}
		}
		cout<<ans;
	}
	return 0;
} 
