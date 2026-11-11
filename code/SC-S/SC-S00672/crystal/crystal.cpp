#include<bits/stdc++.h>//crystal
using namespace std;
const long long N=5e5+100;
long long a,b,c[N],d[N],e,f,g,h;
long long ans=0;
long long abc(long long x)
{
	for(long long i=x;i<=a;i++)
	{
		//提高i-x+1至i号水晶的能量至i好水晶的能量 
		long long u1=c[i];
		long long u2=d[i]-d[i-x];
		long long u3=c[i]*x;
		long long u4=u3-u2;
		if(u4<=b)
		{
			return 1;
		}
	}
	
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(long long i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+1+a);
	for(long long i=1;i<=a;i++)
	{
		d[i]=d[i-1]+c[i];
	}
	long long l=1;
	long long r=a;
	ans=1;
	while(l<=r)//二分答案最终可以用来合成的水晶个数 
	{
		long long mid=(l+r)/2;
		if(abc(mid))
		{
			l=mid+1;
			ans=max(ans,mid);
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;

	return 0;
}
