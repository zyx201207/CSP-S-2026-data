#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
		int n;long long d;cin>>n>>d;int f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>=3)
			{
				if(x[i]-x[i-1]!=x[2]-x[1])
				{
					f=0;
				}
			}
		}
		if(f==1 && n>=4)
		{
			cout<<n-3<<endl;
			return 0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{   
			for(int j=i+3;j<=n;j++)
			{   if(x[j]-x[i]<=d)
				{
					break;
				}
				
				for(int k=i+2;k<=j;k++)
				{   int pl=i;
					if(x[k]-x[pl]<d)
					{
						pl=k-1;
					}
					else if(k==j)
					{
						if(x[k]-x[pl]==d || x[k]-d>x[pl-1])
						{
							break;
						}
					}
				    
				}
				ans++;
				break;
	       }
	 }
	 cout<<ans<<endl;
   }
    return 0;
}

