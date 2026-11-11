#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
map<long long,int> mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int x=m;
	bool bo=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
		{
			bo=0;
		}
		mp[a[i]]++;
	}
	if(bo)
	{
		long long cnt;
		for(int i=1;i<=n;i++)
		{
			m-=i;
			cnt++;
			if(m<0)
			{
				cout<<cnt-1;
				return 0;
			}
		}
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long mx=1;
	for(int i=1;i<=n;i++)
	{
//		cout<<num<<" ";
		if(a[i]==a[i-1]) continue;
		long long l=0,r=i;
		for(int j=21;j>=0;j--)
		{
			if(l+(1<<j)>r)
			{
				continue;
			}
			if((r-l-(1<<j))*a[i]-(sum[r-1]-sum[l+(1<<j)-1])>m)
			{
				l+=(1<<j);
			}
		}
		mx=max(mx,mp[a[i]]+r-l-1);
	}
	cout<<mx;
	return 0;
}
//5 5
//1 2 4 8 9
//5 8
//-3 -1 2 2 7




