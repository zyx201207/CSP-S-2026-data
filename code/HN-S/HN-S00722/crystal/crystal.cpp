#include<bits/stdc++.h>
using namespace std;
long long n,m,b[500005],a[500005],maxx=-1;
bool cmp(long long w,long long e)
{
	return w<e;
}
long long maxans(long long kkk1,long long kkk2)
{
	if(kkk1>kkk2)
	{
		return kkk1;
	}
	return kkk2;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long kuadu=0,l=1,sum=0;//kuadu:首到尾的跨度,sum:需要的值 
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum+b[i]*(i-l);
		kuadu+=b[i];
		while(l<i&&sum>m)
		{
			l++;
			sum-=kuadu;
			kuadu-=b[l];
		}
		maxx=maxans(i-l+1,maxx);
	}
	cout<<maxx;
	return 0;
}
