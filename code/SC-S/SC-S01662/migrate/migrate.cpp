#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t,n,d,ans,g,e,z,f,h,x;
	bool a[2500000],b[1500000][1500000];
	cin>>c>>t;
	for(int o=1;o<=t;o++)
	{
		cin>>n>>d;
		if(d==1) ans=0;
	else
	{
		h=1500000,x=-1500000;
		for(int i=1;i<=n;i++) 
		{
			cin>>g;
			a[g]=1;
			h=min(h,g);
			x=max(x,g);
		} 
		for(int e=h;e<=x-3;e++)
		{
			if(a[e]==0) e++;
			for(int z=e+3;z<=x;z++)
			{
				if(a[z]==0) z++;
				else if(z-e>=2*d) e++;
				else 
				{
					f=0;
					for(int l=e+1;l<z;l++)
					{
						if(a[l]==1&&b[e][z]==0)
						{
							f++;
						}
					}
						b[e][z]=1;
				}
				if(f==2) ans++;
			}
		}
	}
	cout<<ans;
	}
	return 0;
}