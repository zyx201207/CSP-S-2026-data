#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600006],qian[600006],ans,l,r,zhong;
int main()
{
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		qian[i]=qian[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(int i=1;i<=n;i++)
	{
	    l=1;
		r=i;
		while(l!=r)
		{
			if(l+1==r)
			{
				if(qian[i]-qian[l]-(l-1)*(a[i]-a[l-1])<=m)
			    {
				    r=l;
			    }
			    else
			    {
				    l=r;
			    }
			}
			zhong=(l+r)/2;
			if(qian[i]-qian[zhong]-(zhong-1)*(a[i]-a[zhong-1])<=m)
			{
				r=zhong;
			}
			else
			{
				l=zhong;
			}
		}
		ans=max(ans,i-l+1);
	}	
	cout<<ans<<endl;
	return 0;
} 
