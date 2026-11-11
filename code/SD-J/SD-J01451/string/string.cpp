#include<bits/stdc++.h>
using namespace std;
struct st{
	int a;
	char c;
}p[200005];
long long b[200005];
int n;
long long m=0,ans=0;
long long f(long long k)//二分找第几个字母 
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(r-l)/2+l;
		if((b[mid]<k&&b[mid+1]>k)||(b[mid]==k))
		{
			return mid;
		}
		if(b[mid]>k)
		{
			r=mid-1;
		}
		if(b[mid]<k)
		{
			l=mid+1;
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	b[1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].c;
		m+=p[i].a;
		if(i!=1)b[i]=b[i-1]+p[i-1].a;
	}
	b[n+1]=m+1;
	for(long long i=1;i<=(m+1)/2;i++)
	{
		long long l=i,r=m-l+1;
		if(p[f(l)].c!=p[f(r)].c)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
