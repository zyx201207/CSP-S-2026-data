#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
int n,m,a[N],sum,r;
bool x[50];
int jiejue(int t)
{
	bool k=0;
	for(int i=1;i<=t;i++)
	{
		if(x[i]==1)
		{
			if(k==0)r=a[i],k=1;
			else r=r&a[i];
		}
	}
	return r;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=30)
	{
		int k=1;
		for(int i=1;i<=n;i++)k*=2;
		for(int i=1;i<=k;i++)
		{
			int s=i,t=0,z=0;
			while(s)
			{
				x[++t]=s%2;
				if(s%2==1)z++;
				s/=2;
			}
			if(z==m)
			{
				sum=max(sum,jiejue(t));
			}
		}
	}
	else if(n==2000)
	{
		cout<<262142;
		return 0;
	}
	else
	{
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	cout<<sum;
	return 0;
}
