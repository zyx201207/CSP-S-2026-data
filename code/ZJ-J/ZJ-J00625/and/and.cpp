#include<iostream>
#include<bitset>
#include<algorithm>
#define Max 200005
//#define ull unsigned long long
namespace my
{
	using std::cin;
	using std::ios;
	using std::max;
	using std::cout;
	using std::sort;
	using std::bitset;
}
using namespace my;
int n,m,lest;
unsigned long long a[Max];
bitset<Max> sec[32];
//void replace(ull un,int i)
//{
//	int k=0;
//	while(un)
//	{
//		++k;
//		if(un&1)
//		{
//			++len[i];
//			sec[i][k]=1;
//		}		
//		un>>=1;
//	}	
//	lest=max(lest,k);	
//}
//unsigned long long f[Max];
//unsigned long long dp(void)
//{
//	f[1]=a[n];
//	for(int i=1;i<=m;++i)
//	{
//		for(int j=i;j<=n;++j)
//		{
//			f[i]=max(f[i-1],f[i-1]&a[j]);
//		}
//	}
//	return f[m];
//}
unsigned long long baoli(void)
{
	unsigned long long maxn=0,now;
	for(int i=1;i<=n-m+1;++i)
	{
		now=a[i];
		for(int j=i+1;j<=i+m-1;++j)
		{
			now&=a[j];
		}
		maxn=max(maxn,now);
	}
	return maxn;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
//	for(int i=1;i<=n;++i)
//	{
//		replace(a[i],i);
//	}
//	cout<<dp();
	cout<<baoli();
	return 0;
}
