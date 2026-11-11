#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[500005],d[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++)
    {
    	scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=n-1;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long sum=0;
		int check=0;
		for (int i=1;i<mid;i++)
		{
			sum+=a[mid]-a[i];
		}
		if(sum<=m)
		{
			check=1;
		}
		for (int i=2;i<=n-mid;i++)
		{
			sum=sum-(a[i+mid-1]-a[i-1])+(a[i+mid]-a[i+mid-1])*(mid-1);
			if(sum<=m)
		    {
			    check=1;
			    //cout<<i<<" "<<mid<<endl;
			    break;
		    }
	    }
	    if(check==1)
	    {
	    	ans=mid;
	    	l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

