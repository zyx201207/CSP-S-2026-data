#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[5000005],zhu,dang,zhui,b[5000005],ans,zhuis,f,zi,ans1,ans2,j,ji,zm;
signed main()
{
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			dang++;
	 	} 
	 	else
	 	{
	 		//dang++;
	 		if(dang>zhu)
	 		{
	 			zhu=dang;
	 			zhui=a[i-1];
			 }
		}
	}
	if(zhu==0)
	{
		for(int i=1;i<=n;i++)
		{
			zhuis+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			if(zhuis/n==a[i])f=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=zhuis/n)
			{
				zi=i;
				break;
			}
		}
		if(f==1)
		{
			zhui=zhuis/n;
		}
		else
		{
			zhui=min(zhuis/n-a[zi-1],a[zi]-zhuis/n);
		}
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]-zhui;
		if(b[i]==0)
		{
			j++;
			ji=i;	
		}
	}
	sort(b+1,b+1+n);
	int m1;
	m1=m;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<0)
		{
			if(m1>=b[i])
			{
			m1-=b[i];
			ans++;
			}
		}
		if(b[i]==0)
		{
			ans++;
			continue;
		}
		if(b[i]>0)break;
	}
	m1=m;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<0)continue;
		if(b[i]==0)
		{
			ans1++;
			continue;
		}
		if(b[i]>0)
		{
			if(m1>=b[i])
			{
			m-=a[i];
			ans1++;
			continue;
		}
		}
	}
	int fj=0,ii=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]>0)
		{
			fj=i;
			break;
		}
	}
	m1=m;
	while(b[fj]*j+b[fj]*zm<abs(b[ii]))
	{
		ii++;
		if(b[ii]<=m1)
		{
			zm++;
			m1-=b[ii];
			ans2++;
		}
		else
		{
			cout<<max(ans,max(ans1,ans2));
		}
	}
	cout<<max(ans,max(ans1,ans2));
	return 0;
} 
