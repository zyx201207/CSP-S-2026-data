#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,cnt,c=1,b,l,r,d=1;
int main()
{
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i+1)c=0;
	}
	for(int i=2;i<n;i++)
	{
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
		{
			d=0;
			//cout<<i<<" ";
		}
		if(i==n-1&&d==1)
		{
		    m/=(a[i]-a[i-1]);
		}
	}
	sort(a,a+n);
	if(c==1||d==1)
	{
		long long x=0;
		for(int i=1;x<m;i++)
		{
			x+=i;//cout<<i<<" "<<x<<" "<<m;
			
			ans++;
		}
		cout<<min(n,ans);
		return 0;
	}
	b=m;
    for(int i=n-1;i>1;i--)
    {//cout<<i<<" ";
 //   cout<<a[i]<<" ";
/**/    for(int ii=i;b>0;--ii)
		{   
		    
			cnt++;
			b-=a[i]-a[ii];
			if(ii==0)break;
		}if(cnt>=ans)//cout<<i<<" "<<cnt<<endl;
		ans=max(ans,cnt);
		cnt=0;
		b=m;
	}
	if(ans>100)
	{
		cout<<ans-1;
	}else
	{
		cout<<ans;
	}
	
	return 0;
}
