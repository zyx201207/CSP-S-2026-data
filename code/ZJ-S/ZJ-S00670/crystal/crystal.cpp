#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int n,m;
void first()
{
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int k=m,j=i-1,cnt=1;
		while(k>=0&&j>0)
		{
			k-=a[i]-a[j];
			if(k>=0)
			{
				cnt++;
			}
			j--;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
}
void f_100()
{
	int cnt[105],cntn=0,maxn=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++)
	{
		cnt[a[i]]++;
	}
	for(int i=1;i<=100;i++)
	{
		int k=m,j=i,cntn=1,flag=1;
		while(k>=0&&j>0&&flag)
		{
			k-=(i-j)*(cnt[i]-cnt[j]);
			if(k>=0)
			{
				
				cntn+=cnt[j];
			}
			else
			{
				cntn+=(k+(i-j)*(cnt[i]-cnt[j]))/(i-j);
				flag=0;
			}
			j--;
		}
		maxn=min(max(maxn,cntn),n);
	}
	cout<<maxn;
}
void fB()
{
	long long l=1,r=1000000000,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(mid*(mid+1)/2<m)
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	if(mid>=100)
	{
		cout<<100;
		return;
	}
	cout<<mid;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag100=0,flagB=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>100)
		{
			flag100=1;
		}
		if(a[i]-a[i-1]!=1&&i!=1)
		{
			flagB=1;
		}
	}
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		first();
	}
	else if(flag100==0)
	{
		f_100();
	}
	else if(flagB==0)
	{
		fB();
	}
	return 0;
} 
