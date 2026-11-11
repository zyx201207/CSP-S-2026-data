#include<bits/stdc++.h>
using namespace std;

long long n,a[200000],m,l,r,num,dp[200000],chazhi[200000],ma=LLONG_MIN;

struct aw3
{
	long long num,id;
} c[200000];

bool cmp(long long a, long long b)
{
	return a<b;
}

bool cmp1(aw3 a, aw3 b)
{
	if(a.num!=b.num)
	{
		return a.num>b.num;
	}
	return a.id>b.id;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	c[0].id=1;
	for(int i=1;i<n;i++)
	{
		chazhi[i]=abs(a[i]-a[i+1])*i;
		c[i].num=c[i-1].num+chazhi[i];
		c[i].id=i;
	} 
	sort(c+1,c+n,cmp1);
	for(int i=1;i<n;i++)
	{
		if(c[i].num<=m)
		{
			cout<<c[i].id+1;
			return 0;
		}
	}
	return 0;
}
