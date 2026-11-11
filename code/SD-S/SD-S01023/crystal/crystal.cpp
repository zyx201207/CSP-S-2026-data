#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;

#define ll long long 
const int maxn=500010;
ll n,m;
ll a[maxn];

struct node
{
	int w;
	int geshu;
};

vector<node> v;

//bool cmp(const node x,const node y)
//{
//	return x.w<y.w;
//}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool xinga=1,xingb=1;
	scanf("%lld%lld",&n,&m);
	
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
		if(a[i]!=i)
			xinga=0;
		if(i>=3)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				xingb=0;
		}
		
	}
	
	sort(a+1,a+1+n);
	
//	
//	if(maxx<=100005 && minn>=-100005)
//	{
//		ll cnt=1,lay=0,write=0;
//		for(int i=2;i<=n;i++)
//		{
//			v[1].w=a[1];
//			if(a[i]!=a[i-1])
//			{
//				cnt++;
//				v[cnt].w=a[i];
//				v[cnt-1].geshu=i-v[cnt-2].geshu-1;
//				lay=i-1;
//			}
//		}
//		v[cnt].geshu=n-lay;
//		
//		sort(v.begin(),v.end(),cmp);
//		
//		for(int i=1;i<=cnt;i++)//起点枚举 v是下一个起点 
//		{
//			ll ans=0,u=0;
//			for(int j=i+1;j<=cnt;j++)
//			{
//				ans+=(v[j].w-v[j-1].w)*v[j-1].geshu;
//				u+=v[j-1].geshu;
//				if(m<ans)
//				{
//					ll res=u-v[j-2].geshu;
//					res=res+( (m-res)/(v[j].w-v[j-1].w) );
//					write=max(write,res);
//				}
//			} 
//			
//		}
//		
//		cout<<write;
//	}
	if(n<=5005)
	{
		ll y=0;
		for(int k=1;k<=n;k++)
		{	
			ll res=0;
			for(ll i=k;i<=n;i++)
			{
				
				res+=a[i];
				
				ll linshi=a[i]*i;
				ll panduan=linshi-res;
				
				if(m<panduan)
				{
					y=max(y,i-k);
					break;
				}
			}
		}
		cout<<y;
	}
	else if(xinga)
	{
		ll t;
		for(int i=1;;i++)
		{
			t+=i;
			if(t>m)
				cout<<i-1;
		}
	}
	else if(xingb)
	{
		ll d=a[2]-a[1];
		ll t;
		for(int i=1;;i++)
		{
			t+=d*i;
			if(t>m)
			{
				cout<<i-1;
			}
		}
	}
	else 
	{
		cout<<n;
	}

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
