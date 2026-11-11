#include<bits/stdc++.h>
using namespace std;
long long c,d,cha=0,T,n,m,a[2000005],he=0,mm=0,we=0,tong[2000005];
long long ans=0;
int lu(int x,int y)
{
	int ji=0;
	for(int i=x;i+3<=y;i++)
	{
		if(a[i+1]-a[i]>d) return 2;
		if(a[i+1]-a[i]<d&&a[i+2]-a[i]<=d&&a[i+3]-a[i]>d&&a[i+3]-a[i+1]<=d) ji++;
	}
    if(ji==1) return 1;
    else return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		mm=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(i>=2&&a[2]-a[1]!=a[i]-a[i-1]) mm=1;
			//if(i>=2) tong[i-1]=a[i]-a[1];
		}
		if(mm==0)
		{
			if((a[2]-a[1])*3<=d||d<=a[2]-a[1]) cout<<0<<endl;
			else cout<<n-3<<endl;
		}
		else if(n<=5005)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+2;j<=n;j++)
				{
					if(lu(i,j)==1) ans++;
					if(lu(i,j)==2) j=n;
				}
			}
			cout<<ans<<endl;
		}
		else cout<<0<<endl;
	}
	return 0;
}
//for(int i=1,j=i+1;j<=n&&i<=n;j++)
		//	{
		//		if(ji==1&&a[j]-a[i]>d) i=j,ji=0,ans+=(tou+1)*(wei+1),tou=0,wei=0;
		//		if(ji==0&&a[j]-a[i]>d) i=j,tou=0,wei=0;
		//		else if(ji==1&&a[j]-a[i]==d) i=j,wei++;
		//		else if(a[j]-a[i]==d) i=j,tou++;
		//		else if(ji==1&&a[j]-a[i]<d&&a[j+1]-a[i]>d) i=j,wei++;
		//		else if(a[j]-a[i]<d&&a[j+1]-a[i]>d) i=j,tou++;
		//		else if(ji==0&&a[j]-a[i]<d&&a[j+1]-a[i]<=d&&a[j+2]-a[i]>d&&a[j+2]-a[j]<=d) ji=1,i=j+2,j=j+2;
		//		else if(ji==1&&a[j]-a[i]<d&&a[j+1]-a[i]<=d&&a[j+2]-a[i]>d&&a[j+2]-a[j]<=d) ji=1,ans+=(tou+1)*(wei+1),tou=wei,wei=0,i=j+2,j=j+2;
		//	}
		//	cout<<ans<<endl;