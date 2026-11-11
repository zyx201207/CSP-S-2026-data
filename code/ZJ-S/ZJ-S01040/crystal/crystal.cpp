#include<bits/stdc++.h>
using namespace std;
long long a[500005];
vector<long long> dp1(500005,0);
vector<long long> dp2(500005,0);
bool cmp(long long a,long long b)
{
	return a<b;
}
long long fr()
{
	bool neg=false;
	long long res;
	char x=getchar();
	while(1)
	{
		if(x=='-')
		{
			neg=!neg;
		}
		else if(x==' ')
		{
			if(neg)
			{
				return res*-1;
			}
			return res;
		}
		else
		{
			int tmp=(int)x-'0';
			res=res*10+tmp;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;;i++)
	{
		int min=m+1;
		for(int j=i;j<=n;j++)
		{
			if(i%2==0)
			{
				dp1[j]=dp2[j-1]+(i-1)*(a[j]-a[j-1]);
				if(dp1[j]<min)
				{
					min=dp1[j];
				}
				dp2[j-1]=0;
			}
			else
			{
				dp2[j]=dp1[j-1]+(i-1)*(a[j]-a[j-1]);
				if(dp2[j]<min)
				{
					min=dp2[j];
				}
				dp1[j-1]=0;
			}
		}
		if(min>m)
		{
			cout<<i-1;
			return 0;
		}
		if(i%2==0)
		{
			dp2[n]=0;
		}
		else
		{
			dp1[n]=0;
		}
	}
	return 0;
}
