#include<bits/stdc++.h>
using namespace std;
long long n,m,fg;
vector<long long> z;
bool cmp(int x,int y)
{
	return x>y;
}
bool check(int x)
{
	for (int i=1;i+x-1<=n;i++)
	{
		if (z[i+x-1]-z[i-1]-(z[i]-z[i-1])*x<=m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	z.resize(n+5);
	for (int i=1;i<=n;i++)
	{
		cin>>z[i];
	}
	sort(z.begin()+1,z.begin()+n+1,cmp);
	fg=z[1];
	z[0]=z[1]=0;
	for (int i=2;i<=n;i++)
	{
		z[i]=fg-z[i];
		z[i]=z[i]+z[i-1];
	}
	long long l=0,r=n+1,mid;
	while (l<r)
	{
		mid=l+(r-l)/2;
		if (check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	cout<<l-1<<endl;
	return 0;
}
