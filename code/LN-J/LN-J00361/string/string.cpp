#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
long long a[2000005];
string b[2000005];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
    long long n,sum=0,ans=0,l=1,cnt=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum=sum+a[i];
    }
	/*	for(long long i=1;i<=n;i++)
		{
			for(long long j=a[i-1]+1;j<=a[i]+a[i-1];j++)
			{
				 f[j]=b[i];
		    }
	    }
    for(int j=1;j<=sum/2;j++)
    if(f[j]!=f[sum-j+1])
    ans++;
    */
    long long r=sum,kin=n;
    while(1)
    {
		  if(l>a[cnt])
		  {
			  cnt++;
		  }
		  else
		  {
			  l++;
		  }
		  if(r<sum-a[kin]+1)
		  {
			  kin--;
		  }
		  else
		  {
			  r--;
		  }
		  if(b[cnt]!=b[kin])
		  {
			  ans++;
		  }
		  if(cnt>=kin)
		  {
			  break;
		  }
    }
    cout<<ans;
    return 0;
}
