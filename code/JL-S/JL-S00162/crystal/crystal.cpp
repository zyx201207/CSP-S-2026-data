#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long a[N],b[N];
bool cmp(long long a,long long b);
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,cnt=0;
	bool f=true;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)f=false;
	}
	if(!f)
	{
		for(long long i=1;i<=n&&m>=0;i++)
		{
			m=m-i+1;
			cnt++;
		}
		if(m<0)cnt--;
	}
	else 
	{
		sort(a,a+n,cmp);
		b[0]=0;
		for(long long i=0;i<n;i++)
		{
			for(long long j=i+1;j<n;j++)
			{
				b[i]+=a[i]-a[j];
			}
		}
		sort(b,b+n);
		for(long long i=0;i<n;i++)
		{
			if(m>=b[i])cnt++;
			else break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
bool cmp(long long a,long long b)
{
	return a>b;
}
