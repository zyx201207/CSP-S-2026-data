#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],f[1000010],ff[1000010],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else
	{
		if(m==2)
		{
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
				
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
		}
		else
		{
			if(m==n)
			{
				cin>>a[1];
				maxx=a[1];
				for(int i=2;i<=n;i++)
				{
					cin>>a[i];
					maxx=maxx&a[i];
				}
				cout<<maxx;
			}
			else
			{
//				if(m==n-1)
//				{
					for(int i=1;i<=n;i++)
					{
						cin>>a[i];
					}
					f[1]=a[1];
					for(int i=2;i<=n;i++)
					{
						f[i]=f[i-1]&a[i];
					}
					ff[n]=a[n];
					for(int i=n-1;i>=1;i--)
					{
						ff[i]=ff[i+1]&a[i];
					}
					
					for(int i=2;i<=n-1;i++)
					{
						maxx=max(maxx,f[i-1]&ff[i+1]);
						
					}
					maxx=max(maxx,f[n-1]);
					maxx=max(maxx,ff[2]);
					cout<<maxx;
//				}
				
			}
		}
	}
	
	return 0;
}