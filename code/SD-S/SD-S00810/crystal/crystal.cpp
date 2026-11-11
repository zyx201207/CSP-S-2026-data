#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int M = 1e5 + 5;
int a[N],n,d[N];
ll m;
long long ans=0;
void A()
{
	for(int i=0;i<=n;i++)
	{
		if(m-i<0)
		{
			break;
		}
		else
		{
			m-=i;
			ans++;
		}
	}
}
void B()
{
	int D = d[2];
	for(int i=0;i<D*n;i+=D)
	{
		if(m-i<0)
		{
			break;
		}
		else
		{
			m-=i;
			ans++;
		}
	}
}
void opt()
{
	for(int i=n;i>=1;i--)
	{
		int t = m;
		long long cnt = 0;
		for(int j=i;j>=1;j--)
		{
			if(t-a[i]+a[j]>=0)
			{
//				cerr<<t<<' '<<a[i]<<' '<<a[j]<<endl;
				t-=(a[i]-a[j]);
				cnt++;
//				cerr<<cnt<<endl;
			} 
			ans=max(cnt,ans);
		}
//		cerr<<"====="<<endl;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int tmax=-1,num=0;//num出现次数最多的元素tmax它出现的次数 
	sort(a+1,a+n+1);
	bool ta=1,tb=1;
	for(int i=1;i<=n;i++)
	{
		d[i] = a[i] - a[i-1];
		if(i>2&&d[i-1]!=d[i])
		{
			ta=0;
			tb=0;
		}
		if(i!=1&&d[i]!=1) ta=0;
	}
	if(ta)
	{
		A();
	}
	else if(tb)
	{
		B();
	}
	else
	{
		opt();
	}
	printf("%lld\n",ans);
	return 0;
}
