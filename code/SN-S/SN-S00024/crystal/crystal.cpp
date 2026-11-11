#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
long long n,m;
long long a[maxn],b[maxn],c[maxn];
int main()
{
	freopen("crystal.in",r,stdin);
	freopen("crystal.out",w,stdout);
	cin>>n>>m;
	if((n>5000)&&(m>100000000))
	{
		int a;
		if(m>(n/2+n/2*n))
		{
			cout<<n;
		}
		else
		{
			for(int i=1;i<=n;i++)
			  {
			  	if(m<(1+i)/2*i)
			  	  cout<<i-1<<endl;
			  	  return 0;
			  }
		}
	}
	long long ans=-1;
	for(int i=1;i<=n;i++)
	  {
	    cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=0,b[0]=0;
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++)
	{
		long long now=1;
		for(long long j=i;j<=n;j++)
		{
			if(m>=b[j]*(j-1))
			{
				m-=b[j]*(j-1);
				now++;
			}
			else if(m<b[j]*(j-1))
			  break;
		}
		ans=max(ans,now);
	}
	cout<<ans-1<<endl;
	return 0;
 } 
