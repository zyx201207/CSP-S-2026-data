#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int anss[1005];
	for(int i=1;i<=t;i++)
	{
		int n,d,ans1,ans2;
		cin>>n>>d;
		int ans=0;
		int x[200005];
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		
		for(int j=1;j<=n-3;j++)
		{
			int goal=0,nowi=0;
			for(int z=j+3;z<=n;z++)
			{
				goal=z;
				nowi=j;
				if(x[goal]-x[nowi]>d)
				{
					if(x[goal-1]-x[nowi]<=d)
					{
						left=(goal-nowi)/2+1;
						if(x[goal]-x[goal-left]<=d)ans=ans+1;
						
					}
					else
					{
						if(x[goal-2]-x[nowi]<=d)
						{
							if(nowi=goal-3)
							{
								ans+=1;
							}
							else
							{
								ans+=0;
							}
						}
					}
				}
			}
			
		}
		anss[t]=ans;
	}
	for(int i=1;i<=t;i++)
	{
		
		cout<<anss[i]<<endl;
		
	}
	return 0;
}
