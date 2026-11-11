#include<bits/stdc++.h>
using namespace std;
const int N=5*(1e5)+5;
long long k;
long long n,m,tt;
struct ll
{
	long long num;
	long long mi;
};
ll a[N];
bool check(long long sd,long long sum)
{
	
	if(abs(a[sd].num-sum)<=abs(a[sd-1].num-sum)&&abs(a[sd].num-sum)<=abs(a[sd+1].num-sum))
	{
		return true;
	}
	return false;
}
int _find(long long sum) 
{
	int l=0,r=n-1,mid=(r-l)/2+l,ans;
	
	
	while(l!=r)
	{
		if(check(mid,sum))
		{
			ans=mid;
			return ans;
			
		}
		if(a[mid].num<sum)
		{
			l=mid;
		}
		else
		{
			r=mid;
		}
		
		
		mid=ceil((r-l)/2+l);
	}

}

bool cmp(ll x, ll y)
{
	return x.num<y.num;
}
bool cmp2(ll x,ll y)
{
	if(abs(x.mi)==abs(y.mi))
	{
		return x.mi<y.mi;
	}
	return abs(x.mi)<abs(y.mi);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum=0; 
	for(long long i=0;i<n;i++)
	{
		cin>>a[i].num; 
		sum+=a[i].num;

	}
	sort(a,a+n,cmp);
	sum/=n;
	tt=_find(sum);
	for(long long i=0;i<n;i++)
	{
		a[i].mi=a[i].num-a[tt].num;
	}
	sort(a,a+n,cmp2);
	int pp=0;
	for(long long i=0;i<n;i++)
	{
		if(m<a[i].mi)
		{
			break;
		}
		if(a[i].mi<=0)
		{
			m-=abs(a[i].mi);
			pp++;
		}
		else
		{
			if(m>=a[i].mi*pp)
			{
				m-=a[i].mi*pp;
				pp++;
			}
			else
			{
				break;
			}
		}
		
	}
	cout<<pp;
 } 