#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
using namespace std;
long long a[500001],ans,c;
bool cmp(long long x,long long y)
{
	return x>y; 
}
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	S zu guo ran hai shi tai nan le
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	c=a[2]-a[1];
	for(int i=2;i<n;i++)
	{
		if(a[i+1]-a[i]!=c)    f=0;
	}
	if(f)
	{
		long long sum=0,cnt=m;
		for(int i=1;i<=n;i++)
		{
			int num=abs(a[1]-a[i]);
			if(num<=cnt)
			{
				ans++;
				cnt-=num;
			}
			if(cnt<=0)    break;
		}
		cout<<max(ans,sum);
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		long long sum=0,cnt=m;
		for(int j=i;j<=n;j++)
		{
			int num=a[i]-a[j];
			if(num<=cnt)
			{
				sum++;
				cnt-=num;
			}
			if(cnt<=0)    break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

