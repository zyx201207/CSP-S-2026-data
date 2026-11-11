#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],f[4000005],fnt[N],bck[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j,k,ans,l,r,_0,_1,_2,_3;
	bool flag,f1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	flag=true;
	for(i=1;i<=n;i++)
	{
		f1=false;
		for(k=0;k<=30;k++)
		{
			if((1<<k)-1==a[i])
			{
				f1=true;
			}
		}
		if(f1==false)
		{
			flag=false;
			break;
		}
	}
	sort(a+1,a+n+1);
	if(flag==true)
	{
		ans=a[n-m+1];
		for(i=n-m+2;i<=n;i++)
		{
			ans=ans&a[i];
		}
	}
	else if(m==n-1)
	{
		fnt[1]=a[1];
		for(i=2;i<=n;i++)
		{
			fnt[i]=fnt[i-1]&a[i];
		}
		bck[n]=a[n];
		for(i=n-1;i>=1;i--)
		{
			bck[i]=bck[i+1]&a[i];
		}
		ans=max(bck[2],fnt[n-1]);
		for(i=2;i<n;i++)
		{
			ans=max(ans,fnt[i-1]&bck[i+1]);
		}
	}
	else if(a[n]<4)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				_0++;
			}
			else if(a[i]==1)
			{
				_1++;
			}
			else if(a[i]==2)
			{
				_2++;
			}
			else
			{
				_3++;
			}
		}
		if(a[n-m+1]==3)
		{
			ans=3;
		}
		else if(a[n-m+1]==2)
		{
			ans=2;
		}
		else if(a[n-m+1]==1)
		{
			if(_1+_3>=m)
			{
				ans=1;
			}
			else
			{
				ans=0;
			}
		}
		else
		{
			ans=0;
		}
	}
	else
	{
		for(i=0;i<=n;i++)
		{
			f[i*(m+1)]=(1<<30)-1;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				f[i*(m+1)+j]=max(f[(i-1)*(m+1)+j-1]&a[i],f[(i-1)*(m+1)+j]);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,f[i*(m+1)+m]);
		}
	}
	cout<<ans;
	return 0;
}