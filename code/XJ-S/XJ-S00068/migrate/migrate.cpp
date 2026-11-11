#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a[67],f=0,g=99999,h=0,o[779];
	cin>>c>>t;
	for(int s=1;s<=t;s++)
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int y=1;y<=d;y++)
		{
			for(int r=i+1;r<=n;r++)
			{
				if(a[i]+y==a[r])
				{
					f++;
				}
			}
		}	 
 if(g>f)
		{
			g=f;
			f=0;
		}
	 
	 for(int i=1;i<=n;i++)
	{
		if(g==f)
		{
		   h++;
		   f=0;
		}
		for(int y=1;y<=d;y++)
		{
			for(int r=i+1;r<=n;r++)
			{
				if(a[i]+y==a[r])
				{
					f++;
				}
			}
		}	
	
	}

}
 o[t]=h;
}
	
for(int i=1;i<=t;i++)
{
	cout<<o[i]<<endl;
}
return 0;
}
